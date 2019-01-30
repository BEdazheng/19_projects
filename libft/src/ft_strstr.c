/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:10:47 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 13:15:10 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	const char	*tmp;

	tmp = haystack;
	if (!*needle)
		return ((char*)(haystack));
	while (*tmp)
	{
		i = 0;
		tmp = ft_strchr(tmp, needle[i]);
		if (tmp != NULL)
		{
			while (needle[i] != '\0' && tmp[i] != '\0' && tmp[i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return (char*)(tmp);
		}
		else
			return (NULL);
		tmp++;
	}
	return (NULL);
}
