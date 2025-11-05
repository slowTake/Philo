/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:30:07 by pnurmi            #+#    #+#             */
/*   Updated: 2025/11/05 12:32:36 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int handle_error()
{

}
int error_msg(t_error_type type)
{
	if(type == E_NOT_DIGIT)
		return(printf("Not a valid digit"));
	if(type == E_TOO_MANY_ARGS)
		return(printf("too many args"));
	if(type == E_TOO_FEW_ARGS)
		return(printf("too few args"));
}



int cleanup()
{

}