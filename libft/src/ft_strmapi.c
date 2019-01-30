/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:40:06 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/18 16:48:24 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tab = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
	{
		tab[i] = f(i, *s);
		s++;
		i++;
	}
	return (tab);
}
