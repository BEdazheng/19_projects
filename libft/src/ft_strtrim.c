/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:26:32 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 14:17:45 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*tab;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	while (is_space(s[i]))
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (is_space(s[len - 1]))
		len--;
	tab = ft_strnew(len - i);
	tab = ft_strsub(s, i, len - i);
	return (tab);
}
