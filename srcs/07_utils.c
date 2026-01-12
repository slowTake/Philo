/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:44 by pnurmi            #+#    #+#             */
/*   Updated: 2025/12/30 10:48:57 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long long	get_current_time_ms(void)
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
	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->data_mutex);
	if (data->stop_flag && ft_strcmp(status, "died") != 0)
	{
		pthread_mutex_unlock(&data->data_mutex);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->data_mutex);
	printf("%lld %d %s\n", get_current_time_ms() - data->start_time, philo_id,
		status);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}

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
