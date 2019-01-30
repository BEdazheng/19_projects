/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:04:00 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/18 17:18:19 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*tab;

	len = 0;
	if (!s || !f)
		return (NULL);
	if (!(tab = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[len])
	{
		tab[len] = f(s[len]);
		len++;
	}
	return (tab);
}
