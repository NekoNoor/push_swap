/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 15:18:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/06 16:53:01 by nschat        ########   odam.nl         */
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

static int	validate_input(int ac, char **av)
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

static long	*read_into_array(char **av, int len)
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

static int	dupe_check(long *array, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = i;
		while (j < len - 1)
		{
			if (array[i] == array[j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
