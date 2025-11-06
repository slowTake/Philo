/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:30:07 by pnurmi            #+#    #+#             */
/*   Updated: 2025/11/06 14:48:01 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(t_error_type type)
{
	if (type == E_NOT_DIGIT)
		return (printf("Not a valid digit"));
	if (type == E_TOO_MANY_ARGS)
		return (printf("too many args"));
	if (type == E_TOO_FEW_ARGS)
		return (printf("too few args"));
}

void	err_msg(const char *str)
{
	printf("%s", *str);
	return (1);
}

void	err_cleanup(void)
{
}

int	err_invalid(void)
{
	printf("\nPlease enter valid params:");
	printf("\n           Number of philosphers");
	printf("\n           Time to die");
	printf("\n           Time to eat");
	printf("\n           Time to sleep");
	printf("\n           Number of meals to eat (optional)");
	return (1);
}
