/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:03:32 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 14:05:02 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->data, philo->p_id, "has taken a fork");
	while (simulation_finished(philo->data) == 0)
		usleep(100);
	pthread_mutex_unlock(philo->left_fork);
}

static void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo->data, philo->p_id, "has taken a fork");
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_status(philo->data, philo->p_id, "has taken a fork");
}

static void	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->data, philo->p_id, "has taken a fork");
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	if (simulation_finished(philo->data))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_status(philo->data, philo->p_id, "has taken a fork");
}

void	take_forks(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		single_philosopher(philo);
		return ;
	}
	if (philo->p_id % 2 == 0)
		take_forks_even(philo);
	else
		take_forks_odd(philo);
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
