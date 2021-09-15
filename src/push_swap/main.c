/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/15 15:19:55 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*stack_a;
	int		len;
	int		result;

	len = ac - 1;
	if (ac == 1)
		return (error(NOT_ENOUGH_ARGS));
	if (validate_input(ac, av) != 1)
		return (error(NOT_NUMERIC));
	stack_a = read_into_array(av, len);
	if (stack_a == NULL)
		return (error(MALLOC_FAILED));
	result = dupe_range_check(stack_a, len);
	if (result != 1)
	{
		if (result == 0)
			return (error(DUPLICATE_NUM));
		return (error(OUTSIDE_INT));
	}
	free(stack_a);
	return (SUCCESS);
}
