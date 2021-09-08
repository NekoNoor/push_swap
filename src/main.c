/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/08 13:02:49 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*stack_a;
	int		len;

	len = ac - 1;
	if (ac == 1)
	{
		ft_putendl_fd("Error: not enough arguments", 2);
		return (1);
	}
	if (validate_input(ac, av) != 1)
	{
		ft_putendl_fd("Error: input is non-numeric", 2);
		return (2);
	}
	stack_a = read_into_array(av, len);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error: malloc failed", 2);
		return (3);
	}
	if (dupe_check(stack_a, len) != 1)
	{
		ft_putendl_fd("Error: duplicate number found", 2);
		return (4);
	}
	free(stack_a);
	return (0);
}
