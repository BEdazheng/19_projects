/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:46:51 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 11:39:44 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(const char *str, long long *res, int sign)
{
	int	cpt;

	cpt = 0;
	while (*str >= '0' && *str <= '9')
	{
		*res = *res * 10 + (*str++ - '0');
		cpt++;
	}
	*res *= sign;
	if (*str || cpt > 10 || *res > 2147483647 || *res < -2147483648)
		return (0);
	return (1);
}

char		*ft_atoi2(const char *str, long long *res)
{
	int		sign;

	*res = 0;
	sign = 1;
	if (!str || !*str)
		return ("error");
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (is_valid(str, res, sign) == 0)
		return ("error");
	return ("ok");
}
