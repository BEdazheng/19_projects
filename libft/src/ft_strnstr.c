/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:02:08 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 14:18:04 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	count;

	count = 0;
	if (!*needle)
		return ((char*)(haystack));
	while (count < len && *haystack)
	{
		i = 0;
		while (count + i < len && needle[i] == haystack[i] && needle[i])
			i++;
		if (!needle[i])
			return (char*)(haystack);
		count++;
		haystack++;
	}
	return (NULL);
}
