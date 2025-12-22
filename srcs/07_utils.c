/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:44 by pnurmi            #+#    #+#             */
/*   Updated: 2025/12/22 11:09:07 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	if (gettimeofday(&tv, NULL))
		return (1);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

int	print_status(t_data *data, int philo_id, const char *status)
{
	long	timestamp;

	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->data_mutex);
	if (data->stop_flag != 0 && status[0] != 'd')
	{
		pthread_mutex_unlock(&data->data_mutex);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->data_mutex);
	timestamp = get_current_time_ms() - data->start_time;
	printf("%ld %d %s\n", timestamp, philo_id, status);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}
