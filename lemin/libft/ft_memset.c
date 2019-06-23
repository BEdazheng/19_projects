/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:38:12 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/14 22:37:26 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char ch;
	unsigned char *str;

	ch = (unsigned char)c;
	str = (unsigned char*)s;
	while (len-- > 0)
		*(str++) = c;
	return (s);
}
