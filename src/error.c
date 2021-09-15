/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 15:17:25 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/15 15:20:22 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int errornum)
{
	static char	*errors[] = {
		"not enough arguments",
		"input is non-numeric",
		"malloc failed",
		"duplicate number found",
		"number is outside integer range",
	};

	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errors[errornum - 1], 2);
	return (errornum);
}
