/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:33:08 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/15 16:29:59 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *needle, size_t len)
{
	size_t	len_needle;

	if (*needle == '\0')
		return ((char*)hs);
	len_needle = ft_strlen(needle);
	while (*hs != '\0' && len-- >= len_needle)
	{
		if (*hs == *needle && ft_memcmp(hs, needle, len_needle) == 0)
			return ((char*)hs);
		hs++;
	}
	return (NULL);
}
