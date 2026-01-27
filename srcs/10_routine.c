/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:26:28 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/27 09:40:19 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_data *data)
{
	long		total_time;
	long long	start_eat;

	total_time = data->time_to_eat * 1000;
	start_eat = get_current_time_ms();
	while ((get_current_time_ms() - start_eat) < data->time_to_eat)
	{
		usleep(500);
		if (simulation_finished(data))
			return (1);
	}
	return (0);
}

static int	thinking(t_data *data, t_philo *philo)
{
	float		think_time;
	long long	start_think;
	long long	time_left;

	time_left = data->time_to_die - (get_current_time_ms()
			- philo->last_meal_time - data->time_to_eat);
	think_time = (data->time_to_die - data->time_to_eat - data->time_to_sleep);
	if (data->philo_count % 2 == 1)
		think_time = (think_time * 0.75);
	else
		think_time = think_time * 0.25;
	if (think_time > time_left)
		think_time = time_left;
	start_think = get_current_time_ms();
	while (get_current_time_ms() - start_think < think_time)
	{
		if (think_time > data->time_to_die)
			return (1);
		usleep(500);
		if (simulation_finished(data))
			return (1);
	}
	return (0);
}

static int	sleeping(t_data *data)
{
	long long	start_sleep;

	start_sleep = get_current_time_ms();
	while ((get_current_time_ms() - start_sleep) < data->time_to_sleep)
	{
		usleep(500);
		if (simulation_finished(data))
			return (1);
	}
	return (0);
}

static void	philo_loop(t_philo *philo)
{
	while (simulation_finished(philo->data) == 0)
	{
		if (philo->meals_eaten != 0)
		{
			if (simulation_finished(philo->data) == 0)
				print_status(philo->data, philo->p_id, "is thinking");
			if (thinking(philo->data, philo))
				break ;
		}
		if (!take_forks(philo))
		{
			update_last_meal_time(philo);
			if (simulation_finished(philo->data) == 0)
				print_status(philo->data, philo->p_id, "is eating");
			if (eating(philo->data))
			{
				put_forks(philo);
				break ;
			}
			put_forks(philo);
			if (simulation_finished(philo->data) == 0)
				print_status(philo->data, philo->p_id, "is sleeping");
			sleeping(philo->data);
		}
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->p_id % 2 == 0)
		usleep(500);
	philo_loop(philo);
	return (NULL);
}
