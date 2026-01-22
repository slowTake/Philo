/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:57:22 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 14:44:36 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philosopher_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->data_mutex);
	if (get_current_time_ms()
		- data->philosophers[i].last_meal_time > data->time_to_die)
	{
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->data_mutex);
		print_status(data, data->philosophers[i].p_id, "died");
		return (1);
	}
	pthread_mutex_unlock(&data->data_mutex);
	return (0);
}

static int	count_finished_meals(t_data *data)
{
	int	i;
	int	finished_meals;

	i = 0;
	finished_meals = 0;
	while (i < data->philo_count)
	{
		if (check_philosopher_death(data, i))
				return -1;
		pthread_mutex_lock(&data->data_mutex);
		if (data->meals_to_eat > 0
			&& data->philosophers[i].meals_eaten >= data->meals_to_eat)
			finished_meals++;
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	return (finished_meals);
}

static void	check_all_finished(t_data *data, int finished_meals)
{
	if (data->meals_to_eat > 0 && finished_meals == data->philo_count)
	{
		pthread_mutex_lock(&data->data_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->data_mutex);
	}
}

void	monitor(t_data *data)
{
	int	i;
	int	finished_meals;

	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (check_philosopher_death(data, i))
				return ;
			i++;
		}
		finished_meals = count_finished_meals(data);
		if(finished_meals == -1)
			return ;
		check_all_finished(data, finished_meals);
		if (data->stop_flag)
			return ;
		usleep(500);
	}
}
