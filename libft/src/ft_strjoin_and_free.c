/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:18:59 by dazheng           #+#    #+#             */
/*   Updated: 2018/10/29 18:00:00 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char const *s1, char const *s2, int option)
{
	char *tab;

	if (!s1 || !s2)
		return (NULL);
	if (!(tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(tab, s1);
	ft_strcat(tab, s2);
	if (option == 0)
		free((char*)s1);
	else if (option == 1)
		free((char*)s2);
	else
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (tab);
}
