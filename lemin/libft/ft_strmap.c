/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:41:39 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/22 13:27:53 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*dup;
	char	*tmp;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	tmp = dup;
	i = 0;
	while (s[i])
	{
		dup[i] = f(s[i]);
		i++;
	}
	dup[i] = '\0';
	return (tmp);
}
