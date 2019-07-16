/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:34:19 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 12:00:03 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*is_special(int n)
{
	char	*str;

	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		return (ft_strdup("0"));
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	return ("Faux");
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		count;

	if (n == 0 || n == -2147483648)
		return (is_special(n));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	count = count_char(n) + sign;
	if (!(str = ft_strnew(count)))
		return (NULL);
	count--;
	while (n != 0)
	{
		str[count--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
