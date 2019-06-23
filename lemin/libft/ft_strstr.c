/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:14:17 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/15 16:13:40 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle == '\0')
		return ((char*)haystack);
	len = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, len) != 0)
		haystack++;
	if (*haystack == '\0')
		return (NULL);
	return ((char*)haystack);
}
