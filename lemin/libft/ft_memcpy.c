/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:06:50 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/19 00:18:38 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (src == dst || n == 0)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (--n)
		*d++ = *s++;
	*d = *s;
	return (dst);
}
