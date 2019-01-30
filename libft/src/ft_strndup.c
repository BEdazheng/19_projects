/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:01:16 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/21 15:06:49 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char *tab;

	if ((tab = ft_strnew(len)) == NULL)
		return (NULL);
	tab = ft_strncpy(tab, s, len);
	return (tab);
}
