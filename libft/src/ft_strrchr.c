/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:22:25 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/16 13:07:57 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int occur;
	int count;

	count = 0;
	occur = -1;
	while (*s)
	{
		s++;
		count++;
	}
	while (count >= 0 && *s != (char)c)
	{
		count--;
		s--;
	}
	if (*s == (char)c)
		return ((char*)(s));
	return (NULL);
}
