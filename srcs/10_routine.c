/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:26:28 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/25 17:20:44 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_data *data)
{
	long	total_time;
	int		i;

	total_time = data->time_to_eat * 1000;
	i = 0;
	while (i < 3)
	{
		usleep(total_time / 3);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

static int	thinking(t_data *data, t_philo *philo)
{
	long	think_time;
	int		i;

	think_time = ((get_current_time_ms() - philo->last_meal_time) / 2);
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
	while (i < 3)
	{
		usleep(sleep_time / 3);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

static void philo_loop(t_philo *philo)
{
	while (simulation_finished(philo->data) == 0)
	{
		print_status(philo->data, philo->p_id, "is thinking");
		if (thinking(philo->data, philo))
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
}

void *philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->p_id % 2 == 1)
	{
		if (philo->data->philo_count == philo->p_id)
			usleep(1000);
		else
			usleep(5700);
	}
	philo_loop(philo);
	return (NULL);
}
