/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:45:14 by dazheng           #+#    #+#             */
/*   Updated: 2018/08/02 16:59:53 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static int			wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

static char const	*skip_char(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb_words;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		s = skip_char(s, c);
		j = 0;
		len = wordlen(s, c);
		tab[i] = ft_strnew(len);
		while (j < len)
			tab[i][j++] = *s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
