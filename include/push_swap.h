/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:26 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/08 13:36:30 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		validate_input(int ac, char **av);
long	*read_into_array(char **av, int len);
int		dupe_check(long *array, int len);

#endif
