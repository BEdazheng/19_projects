/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:11:32 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 12:50:06 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *tmp;

	if (n == 0)
		return (NULL);
	tmp = s;
	while (n > 0)
	{
		if ((unsigned char)c == *tmp)
			return (void*)(s);
		tmp++;
		s++;
		n--;
	}
	return (NULL);
}
