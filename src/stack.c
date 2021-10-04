/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 11:35:42 by nschat        #+#    #+#                 */
/*   Updated: 2021/10/04 15:11:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	 *create_stacks(int *array, int len)
{
	t_stacks		*both_stacks;
	t_stack_list	*current;
	int			i;

	both_stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (both_stacks == NULL)
		return (NULL);
	both_stacks->stacks = (t_stack_list *)malloc(sizeof(t_stack_list) * len);
	if (both_stacks->stacks == NULL)
		return (NULL);
	both_stacks->a_top = both_stacks->stacks;
	both_stacks->b_top = NULL;
	i = 0;
	current = both_stacks->stacks;
	while (i < len)
	{
		current[i].next = &current[i + 1];
		current[i].prev = &current[i - 1];
		current[i].value = array[i];
		i++;
	}
	return (both_stacks);
}
