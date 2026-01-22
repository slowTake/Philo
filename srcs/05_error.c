/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:09:00 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 14:08:09 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_msg(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int	err_invalid(void)
{
	printf("\nPlease enter valid params:");
	printf("\n  -Number of philosphers");
	printf("\n  -Time to die");
	printf("\n  -Time to eat");
	printf("\n  -Time to sleep");
	printf("\n  -Number of meals to eat (optional)");
	return (1);
}
