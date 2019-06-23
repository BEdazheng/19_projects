/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:27:58 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/22 13:31:35 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*tmp;
	size_t	n;

	tmp = dest;
	n = len;
	while (*src && len)
	{
		*dest++ = *src++;
		len--;
	}
	while (len)
	{
		*dest++ = '\0';
		len--;
	}
	return (tmp);
}
