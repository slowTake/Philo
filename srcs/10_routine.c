/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:26:28 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 17:00:21 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo, t_data *data)
{
	long	total_time;
	int		i;

	update_last_meal_time(philo);
	total_time = data->time_to_eat * 1000;
	i = 0;
	while (i < 10)
	{
		usleep(total_time / 10);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

static int	thinking(t_philo *philo, t_data *data)
{
	long	think_time;
	int		i;

	think_time = 500;
	if (philo->p_id % 2 == 0)
		think_time = 1500;
	if (data->philo_count % 2 != 0)
		think_time = 500;
	i = 0;
	while (i < 10)
	{
		usleep(think_time / 10);
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
	while (i < 10)
	{
		usleep(sleep_time / 10);
		if (simulation_finished(data))
			return (1);
		i++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->p_id % 2 == 0)
		usleep(1500);
	while (simulation_finished(philo->data) == 0)
	{
		print_status(philo->data, philo->p_id, "is thinking");
		if (thinking(philo, philo->data))
			break ;
		take_forks(philo);
		if (simulation_finished(philo->data))
			break ;
		print_status(philo->data, philo->p_id, "is eating");
		if (eating(philo, philo->data))
		{
			put_forks(philo);
			break ;
		}
		put_forks(philo);
		print_status(philo->data, philo->p_id, "is sleeping");
		sleeping(philo->data);
	}
	return (NULL);
}
