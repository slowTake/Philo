/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:26:56 by pnurmi            #+#    #+#             */
/*   Updated: 2025/11/05 15:06:38 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_validation(int argc, char **argv, t_data data)
{
	int	i;

	i = 0;
	if (argc != 4 && argc != 5)
		return (err_msg(E_NOT_DIGIT));
	while (argv[i])
	{
		if (isdigit(argv[1][i]) != 1)
			return (printf("Not a digit"));
		if (argv[1][i] <= 1)
			return (printf("Not Positive"));
		i++;
	}
	parsing(**argv, data);
}

void	parsing(char **argv, t_data data)
{

		data->philos_num = str_int(argv[1][0]);
		data->philos_num = str_int(argv[1][1]);
		data->philos_num = str_int(argv[1][2]);
		data->philos_num = str_int(argv[1][3]);
}

int str_int(char *str)
{
	
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
