/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:16:28 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/06 15:29:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numlen_base(int n, int base)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_base(int n, int base)
{
	static const char	set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char				*str;
	long				nbr;
	int					i;

	if (base < 2 || base > 36)
		return (NULL);
	str = (char *)malloc((ft_numlen_base(n, base) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	nbr = n;
	if (n < 0)
		nbr = -(long)n;
	i = 0;
	if (nbr == 0)
		str[i] = '0';
	while (nbr)
	{
		str[i] = set[nbr % base];
		nbr /= base;
		i++;
	}
	if (n < 0 && base == 10)
		str[i] = '-';
	i += ((n < 0 && base == 10) || n == 0);
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
