/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:44:15 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/17 18:53:13 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	dup = ft_strdup((char*)s);
	if (dup == NULL)
		return (NULL);
	while (dup[i])
	{
		dup[i] = f(i, dup[i]);
		i++;
	}
	return (dup);
}
