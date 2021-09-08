/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 13:01:55 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/08 13:12:34 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_isnumeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (-1);
	if (*str == '+' && *(str + 1) != '\0')
		str++;
	if (*str == '-' && *(str + 1) != '\0')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) != 1)
			return (0);
		str++;
	}
	return (1);
}

int	validate_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (str_isnumeric(av[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

long	*read_into_array(char **av, int len)
{
	long	*array;
	int		i;

	array = malloc(sizeof(long) * len);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = ft_strtol(av[i + 1], 10);
		i++;
	}
	return (array);
}

static int	check(long *array, int current, int len)
{
	int	i;

	i = current;
	while (i < len - 1)
	{
		if (array[current] == array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	dupe_check(long *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (check(array, i, len) != 1)
			return (0);
		i++;
	}
	return (1);
}
