/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:12:19 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/21 15:49:19 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		count++;
	}
	return (count);
}

char		*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*str;
	int		sign;

	sign = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16 || (value < 0 && base != 10))
		return (0);
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	sign = value < 0 ? 1 : 0;
	value = value < 0 ? -value : value;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count(value, base) + sign))))
		return (NULL);
	str[ft_count(value, base) + sign] = '\0';
	while (value != 0)
	{
		str[ft_count(value, base) - 1 + sign] = tab[value % base];
		value = value / base;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
