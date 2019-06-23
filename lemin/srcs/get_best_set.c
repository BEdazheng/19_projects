/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:03:41 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/24 13:50:03 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int	calculate(t_li *li, int i, int nb_path)
{
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (++j < i)
		count += li->room_set_tmp[i]->length - li->room_set_tmp[j]->length + 1;
	if (li->nb_ants > count)
	{
		j = -1;
		while (++j < i)
			li->tab_ants_per_path_tmp[j] =
				li->room_set_tmp[i]->length - li->room_set_tmp[j]->length + 1;
		li->tab_ants_per_path_tmp[j] = 1;
	}
	if (nb_path > i + 1 && li->nb_ants > count)
		calculate(li, i + 1, nb_path);
	return (1);
}

static void	sort_set(t_li *li)
{
	t_room_set	*tmp;
	int			i;
	int			j;

	i = 0;
	while (li->room_set_tmp[i])
	{
		j = 0;
		while (li->room_set_tmp[j])
		{
			if (li->room_set_tmp[j]->length > li->room_set_tmp[i]->length)
			{
				tmp = li->room_set_tmp[i];
				li->room_set_tmp[i] = li->room_set_tmp[j];
				li->room_set_tmp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_ants_per_path(t_li *li, int nb_path)
{
	int	count;
	int	i;
	int	tmp;
	int	nb_path_used;

	i = -1;
	count = 0;
	while (++i < nb_path)
		count += li->tab_ants_per_path_tmp[i];
	i = -1;
	nb_path_used = 0;
	while (++i < nb_path && li->tab_ants_per_path_tmp[i])
		nb_path_used++;
	count = li->nb_ants - count;
	tmp = count / nb_path_used;
	i = -1;
	while (++i < nb_path_used)
		li->tab_ants_per_path_tmp[i] += tmp;
	count = count - (tmp * nb_path_used);
	i = -1;
	while (++i < nb_path_used && count != 0)
	{
		li->tab_ants_per_path_tmp[i] += 1;
		count--;
	}
}

static int	compare(t_li *li, int nb_turns)
{
	if (!li->room_set)
	{
		li->nb_turns = nb_turns;
		li->room_set = li->room_set_tmp;
		li->tab_ants_per_path = li->tab_ants_per_path_tmp;
	}
	else if (nb_turns < li->nb_turns)
	{
		garbage_roomset(li->room_set);
		li->room_set = li->room_set_tmp;
		li->nb_turns = nb_turns;
		free(li->tab_ants_per_path);
		li->tab_ants_per_path = li->tab_ants_per_path_tmp;
	}
	else
	{
		free(li->tab_ants_per_path_tmp);
		garbage_roomset(li->room_set_tmp);
		return (0);
	}
	return (1);
}

int			get_best_set(t_li *li, int nb_path)
{
	int	nb_turns;

	sort_set(li);
	if (!(li->tab_ants_per_path_tmp = (int*)malloc(sizeof(int) * nb_path)))
	{
		garbage_roomset(li->room_set_tmp);
		li->error = 2;
		return (0);
	}
	ft_bzero(li->tab_ants_per_path_tmp, 4 * nb_path);
	li->tab_ants_per_path_tmp[0] = 1;
	if (nb_path > 1)
	{
		calculate(li, 1, nb_path);
		fill_ants_per_path(li, nb_path);
	}
	else
		li->tab_ants_per_path_tmp[0] = li->nb_ants;
	nb_turns = li->tab_ants_per_path_tmp[0] + li->room_set_tmp[0]->length - 1;
	return (compare(li, nb_turns));
}
