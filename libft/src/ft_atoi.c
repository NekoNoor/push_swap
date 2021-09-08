/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:21 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/08 13:50:57 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static unsigned char	ft_getvalue(char c, int base)
{
	if (base <= 10 && c >= '0' && c <= base - 1 + '0')
		return (c - '0');
	if (base > 10 && ft_isdigit(c))
		return (c - '0');
	if (base > 10 && c >= 'A' && c <= base - 10 - 1 + 'A')
		return (c - 'A' + 10);
	if (base > 10 && c >= 'a' && c <= base - 10 - 1 + 'a')
		return (c - 'a' + 10);
	return (255);
}

static int	limit_check(int base, int sign, unsigned long nbr,
		unsigned char value)
{
	unsigned long	max;
	int				lim;

	max = LONG_MAX;
	if (sign == -1)
		max = (unsigned long)LONG_MAX + 1;
	lim = 7;
	if (sign == -1)
		lim = 8;
	max /= base;
	if (nbr > max || (nbr == max && value > lim))
		return (1);
	return (0);
}

long	ft_strtol(const char *str, int base)
{
	int				sign;
	unsigned long	nbr;

	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (base == 10 && *str == '-')
		sign = -1;
	if (base == 10 && (*str == '+' || *str == '-'))
		str++;
	nbr = 0;
	while (ft_getvalue(*str, base) != 255)
	{
		if (limit_check(base, sign, nbr, ft_getvalue(*str, base)) != 0)
		{
			if (sign == -1)
				return (LONG_MIN);
			return (LONG_MAX);
		}	
		nbr = nbr * base + ft_getvalue(*str, base);
		str++;
	}
	return ((long)(nbr * sign));
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, 10));
}
