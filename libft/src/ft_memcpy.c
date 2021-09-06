/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:18 by nschat        #+#    #+#                 */
/*   Updated: 2021/09/06 15:23:13 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			((unsigned char *)dst)[n] = ((unsigned const char *)src)[n];
		}
	}
	return (dst);
}
