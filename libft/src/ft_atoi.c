/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:58:52 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 12:36:12 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				neg;
	unsigned long	nb;

	nb = 0;
	neg = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' ||
			*str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
		if (nb > 9223372036854775807 && neg == 1)
			return (-1);
		else if (nb > 9223372036854775807 && neg == -1)
			return (0);
	}
	return ((int)(nb * neg));
}
