/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:53:45 by pnurmi            #+#    #+#             */
/*   Updated: 2025/11/06 14:53:14 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	parsing(argc, argv[1], data);
	monitor;
	cleanup;
}
