/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/02 16:32:56 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_isnumeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (-1);
	if (*str == '-' && *(str + 1) != '\0')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		ft_putendl_fd("Error: not enough arguments", 2);
	i = 1;
	while (i < ac)
	{
		if (str_isnumeric(av[i]) != 1)
		{
			ft_putendl_fd("Error: input is non-numeric", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
