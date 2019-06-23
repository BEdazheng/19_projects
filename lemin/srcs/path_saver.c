/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:20:33 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/22 17:55:29 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static t_room_set	*new_path(t_room *room, t_room_set *prev)
{
	t_room_set	*set;

	set = (t_room_set*)malloc(sizeof(t_room_set));
	set->length = 0;
	set->ant_num = 0;
	set->room = room;
	set->prev = prev;
	set->next = NULL;
	return (set);
}

static t_room_set	*find_last_room_set(t_li *li, int cpt_path)
{
	t_room_set	*tmp;

	if (!li->room_set_tmp[cpt_path])
		return (NULL);
	tmp = li->room_set_tmp[cpt_path];
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int					add_path(t_li *li, t_room *start, int cpt_path)
{
	t_room_set	*new_set;

	new_set = find_last_room_set(li, cpt_path);
	if (new_set == NULL)
	{
		if (!(new_set = new_path(start, NULL)))
			return (0);
		li->room_set_tmp[cpt_path] = new_set;
	}
	else if (!(new_set->next = new_path(start, new_set)))
		return (0);
	return (1);
}

int					save_path(t_li *li, t_room *start, int cpt_path)
{
	int			i;
	t_room_set	*new_set;

	i = -1;
	if (start->number == li->end->number)
	{
		new_set = find_last_room_set(li, cpt_path);
		if (!(new_set->next = new_path(start, new_set)))
			return (0);
		li->room_set_tmp[cpt_path]->end = new_set->next;
		return (1);
	}
	while (start->link[++i])
	{
		if (start->link[i]->visited == 1 && !start->link[i]->reverse->visited)
		{
			if (!add_path(li, start, cpt_path))
				return (0);
			if (!save_path(li, start->link[i]->room, cpt_path))
				return (0);
			cpt_path++;
		}
	}
	return (1);
}
