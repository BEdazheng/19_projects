/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:17:13 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/18 21:48:21 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int		ft_isnegative(int *n, int *sign)
{
	if (*n < 0)
	{
		*n *= -1;
		*sign = -1;
		return (1);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = 1;
	if (n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (ft_isnegative(&n, &sign))
		(len = length(n) + 1);
	else
		(len = length(n));
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (sign == -1)
		res[0] = '-';
	res[len] = '\0';
	while (n > 0)
	{
		len--;
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
