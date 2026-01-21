/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:57 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/21 13:50:43 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_memory(t_data *data)
{
	size_t	n;
	size_t	philo_size;
	size_t	forks_size;

	if (data->philo_count <= 0)
		return (err_msg("Invalid number of philosophers"));
	n = (size_t)data->philo_count;
	philo_size = n * sizeof(*data->philosophers);
	forks_size = n * sizeof(*data->forks);
	if (n > SIZE_MAX / sizeof(*data->philosophers) || n > SIZE_MAX
		/ sizeof(*data->forks))
		return (err_msg("Allocation size overflow"));
	data->philosophers = malloc(philo_size);
	if (data->philosophers == NULL)
		return (err_msg("Philo alloc failed"));
	memset(data->philosophers, 0, philo_size);
	data->forks = malloc(forks_size);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		data->philosophers = NULL;
		return (err_msg("Fork alloc failed"));
	}
	memset(data->forks, 0, forks_size);
	return (0);
}
