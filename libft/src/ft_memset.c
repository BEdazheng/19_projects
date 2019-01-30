/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:23:08 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/16 16:15:49 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*tmp;

	tmp = b;
	i = 0;
	while (i < len)
	{
		*tmp = (unsigned char)c;
		tmp++;
		i++;
	}
	return (b);
}
