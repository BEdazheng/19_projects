/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:50:17 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/14 22:40:39 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len_dst;
	size_t		siz;

	s = src;
	d = dst;
	siz = size;
	while (siz-- && *d)
		d++;
	len_dst = d - dst;
	siz = size - len_dst;
	if (siz == 0)
		return (len_dst + ft_strlen(s));
	while (*src)
	{
		if (siz != 1)
		{
			*d++ = *src;
			siz--;
		}
		src++;
	}
	*d = '\0';
	return (len_dst + (src - s));
}
