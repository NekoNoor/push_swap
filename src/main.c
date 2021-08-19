/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/08/19 14:40:31 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int 	str_isnumeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (-1);
	if (*str == '-' && *(str + 1) != '\0')
		str++;
	while (*str != '\0')
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		write(2, "Error: not enough arguments\n", 28);
	i = 1;
	while (i < ac)
	{
		if (str_isnumeric(av[i]) != 1)
		{
			write(2, "Error: input is non-numeric\n", 28);
			return (1);
		}
		i++;
	}
	return (0);
}
