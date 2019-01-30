/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:48:14 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/18 23:29:41 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	while (n > 0)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		n--;
	}
	return (dst);
}
