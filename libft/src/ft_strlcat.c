/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:23:29 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/21 14:58:28 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	len;
	unsigned long	max_len;
	int				i;

	max_len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	len = ft_strlen(dst);
	if (size >= len && size < (len + 2))
		return (ft_strlen(dst) + ft_strlen(src));
	else if (size < len)
		return (ft_strlen(src) + size);
	else
	{
		while (len < size - 1 && src[i] != '\0')
		{
			dst[len] = src[i];
			len++;
			i++;
		}
		dst[len] = '\0';
	}
	return (max_len);
}
