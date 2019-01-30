/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:42:09 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/17 18:39:02 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tab;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1;
		i++;
		s1++;
	}
	tab[i] = '\0';
	return (tab);
}
