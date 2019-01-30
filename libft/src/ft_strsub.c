/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:55:18 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 10:11:45 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	int				i;
	unsigned long	stop;

	stop = start;
	i = 0;
	if (!(tab = ft_strnew(len)) || !s)
		return (NULL);
	while (start < stop + len && s[start])
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	return (tab);
}
