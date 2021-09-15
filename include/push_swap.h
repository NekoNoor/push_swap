/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:26 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/15 15:19:55 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

enum e_errornums {
	SUCCESS,
	NOT_ENOUGH_ARGS,
	NOT_NUMERIC,
	MALLOC_FAILED,
	DUPLICATE_NUM,
	OUTSIDE_INT,
};

typedef struct s_stack_list {
	int					value;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}		t_stack_list;

typedef struct s_stacks {
	t_stack_list	*stacks;
	t_stack_list	*a_top;
	t_stack_list	*a_base;
	t_stack_list	*b_top;
	t_stack_list	*b_base;
}		t_stacks;

int		error(int errornum);
int		validate_input(int ac, char **av);
long	*read_into_array(char **av, int len);
int		dupe_range_check(long *array, int len);

#endif
