/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/08 13:39:53 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(int errornum)
{
	static char	*errors[] = {
		"not enough arguments",
		"input is non-numeric",
		"malloc failed",
		"duplicate number found"
	};

	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errors[errornum - 1], 2);
	return (errornum);
}

int	main(int ac, char **av)
{
	long	*stack_a;
	int		len;

	len = ac - 1;
	if (ac == 1)
		return (error(1));
	if (validate_input(ac, av) != 1)
		return (error(2));
	stack_a = read_into_array(av, len);
	if (stack_a == NULL)
		return (error(3));
	if (dupe_check(stack_a, len) != 1)
		return (error(4));
	free(stack_a);
	return (0);
}
