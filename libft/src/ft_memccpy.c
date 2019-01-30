/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:33:57 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/17 16:45:45 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *src2;
	unsigned char *dst2;
	unsigned char x;

	x = c;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		if ((*src2) == x)
		{
			*dst2 = *src2;
			return (dst2 + 1);
		}
		*dst2 = *src2;
		src2++;
		dst2++;
		n--;
	}
	return (NULL);
}
