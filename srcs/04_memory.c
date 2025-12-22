/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:57 by pnurmi            #+#    #+#             */
/*   Updated: 2025/12/22 11:08:58 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_memory(t_data *data)
{
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (data->philosophers == NULL)
		return (err_msg("Phillo alloc failed"));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->philo_count);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		data->philosophers = NULL;
		return (err_msg("Fork alloc failed"));
	}
	return (0);
}
