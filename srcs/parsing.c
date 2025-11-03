/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:26:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/11/03 12:29:59 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(int argc, char **argv, t_data data)
{
	int i = 0;
	if (argc != 4 && argc != 5)
		return (printf("Invalid arguement"));
	if(isdigit(argv[1][i]) != 1)
		return(printf("Not a digit"));
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
