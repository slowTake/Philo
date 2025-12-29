/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:53 by pnurmi            #+#    #+#             */
/*   Updated: 2025/12/29 15:04:38 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philosophers[i].t_id, NULL) != 0)
			printf("Error joining thread %d\n", i);
		i++;
	}
}

int	execution_main(t_data *data)
{
	if (init_resources(data) != 0)
	{
		cleanup_data(data);
		return (1);
	}
	if (init_threads(data) != 0)
	{
		cleanup_data(data);
		return (1);
	}
	monitor(data);
	wait_for_threads(data);
	cleanup_data(data);
	return (0);
}

int	init_resources(t_data *data)
{
	if (init_fork(data) == 1)
		return (1);
	if (init_ctrl_mutexes(data) == 1)
	{
		cleanup_mutexes(data, data->philo_count);
		return (1);
	}
	if (init_philo_data(data) == 1)
		return (1);
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_current_time_ms();
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philosophers[i].t_id, NULL, &philo_routine,
				&data->philosophers[i]) != 0)
		{
			cleanup_threads(data, i);
			return (1);
		}
		data->philosophers[i].last_meal_time = data->start_time;
		i++;
	}
	return (0);
}

void	monitor(t_data *data)
{
	int	i;
	int	finished_meals;

	while (1)
	{
		finished_meals = 0;
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_lock(&data->data_mutex);
			if (get_current_time_ms()
				- data->philosophers[i].last_meal_time > data->time_to_die)
			{
				data->stop_flag = 1;
				pthread_mutex_unlock(&data->data_mutex);
				print_status(data, data->philosophers[i].p_id, "died");
				return ;
			}
			if (data->meals_to_eat > 0
				&& data->philosophers[i].meals_eaten >= data->meals_to_eat)
				finished_meals++;
			pthread_mutex_unlock(&data->data_mutex);
			i++;
		}
		if (data->meals_to_eat > 0 && finished_meals == data->philo_count)
		{
			pthread_mutex_lock(&data->data_mutex);
			data->stop_flag = 1;
			pthread_mutex_unlock(&data->data_mutex);
			return ;
		}
		usleep(1000);
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->data, philo->p_id, "has taken a fork");
		while (simulation_finished(philo->data) == 0)
			usleep(100);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (philo->p_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->data, philo->p_id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->data, philo->p_id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->data, philo->p_id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->data, philo->p_id, "has taken a fork");
	}
}

void	put_forks(t_philo *philo)
{
	if (philo->p_id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->last_meal_time = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->data_mutex);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->p_id % 2 == 0)
		usleep(1500);
	while (simulation_finished(data) == 0)
	{
		print_status(data, philo->p_id, "is thinking");
		if (data->philo_count % 2 != 0)
			usleep(500);
		take_forks(philo);
		if (simulation_finished(data) != 0)
			break ;
		print_status(data, philo->p_id, "is eating");
		update_last_meal_time(philo);
		usleep(data->time_to_eat * 1000);
		put_forks(philo);
		print_status(data, philo->p_id, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	return (NULL);
}
