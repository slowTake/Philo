/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:26:28 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/25 12:54:26 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_data *data)
{
	long	total_time;
	int		i;

	total_time = data->time_to_eat * 1000;
	i = 0;
	while (i < 5)
	{
		usleep(total_time / 5);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

static int	thinking(t_data *data)
{
	long	think_time;
	int		i;

	think_time = data->time_to_eat * 1000;
	i = 0;
	while (i < 5)
	{
		usleep(think_time / 5);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

static int	sleeping(t_data *data)
{
	long	sleep_time;
	int		i;

	sleep_time = data->time_to_sleep * 1000;
	i = 0;
	while (i < 5)
	{
		usleep(sleep_time / 5);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	long	initial_delay;

	philo = (t_philo *)arg;
	// while (philo->data->start_time >= get_current_time_ms())
		// usleep(500);
	if (philo->data->philo_count % 2 != 0)
	{
		initial_delay = (philo->p_id * philo->data->time_to_sleep)
			/ philo->data->philo_count * 100;
		usleep(initial_delay);
	}
	while (simulation_finished(philo->data) == 0)
	{
		print_status(philo->data, philo->p_id, "is thinking");
		if (thinking(philo->data))
			break ;
		if (!take_forks(philo))
		{
			update_last_meal_time(philo);
			print_status(philo->data, philo->p_id, "is eating");
			if (eating(philo->data))
			{
				put_forks(philo);
				break ;
			}
			put_forks(philo);
			print_status(philo->data, philo->p_id, "is sleeping");
			sleeping(philo->data);
		}
	}
	return (NULL);
}
