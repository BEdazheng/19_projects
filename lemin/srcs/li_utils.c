/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 02:53:30 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 15:24:49 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		li_init(t_li *li)
{
	li->data = NULL;
	li->nb_ants = -1;
	li->start_name = NULL;
	li->end_name = NULL;
	li->error = 0;
	li->nb_start_end = 0;
	li->tunnel_exist = 0;
	li->reading_tunnel = 0;
	li->max_way = 0;
	li->nb_turns = 2147483647;
	li->tab_ants_per_path = NULL;
	li->tab_ants_per_path_tmp = NULL;
	li->start = NULL;
	li->end = NULL;
	li->room_set = NULL;
	li->room_set_tmp = NULL;
}

/*
**	set the initial state of the created room.
**	to know what data contain (cd. lem_in.h -> struct s_room)
*/

static void	set_room_data(t_room *room, char **tab)
{
	static int num = 1;

	room->dist = WEIGHT_MAX;
	room->used = 0;
	room->number = num;
	room->data = tab;
	room->father = NULL;
	room->status = 0;
	room->queue = NULL;
	room->link = NULL;
	room->next = NULL;
	num++;
}

/*
**	Create a new room ! WOW REALLY ?
*/

t_li		*new_room(t_li *li, char **tab)
{
	t_room	*new_room;

	if (li)
	{
		if ((new_room = (t_room*)malloc(sizeof(t_room))))
		{
			set_room_data(new_room, tab);
			if (li->end == NULL)
			{
				li->start = new_room;
				li->end = new_room;
			}
			else
			{
				li->end->next = new_room;
				li->end = new_room;
			}
		}
	}
	return (li);
}

/*
**	Calculate the max number of simultaneous way we can have in a set.
**	Set the starting and ending room depending on the number of links of start
**	and end.
**	This mean if the Start room have 5 links and the End room only 3 links.
**	Will start looking for path from the End room instead of the Start room.
**	That way instead of looking for !(5) = 120 set of 5 max paths,
**	we will look for !(3) = 6 set of 3 paths, that's logic.
**
**	And then we will create or list of starting link, which will be all the
**	links directly connect to the starting room we choosed.
*/

int			is_directly_linked(t_li *li)
{
	t_room	*room;
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	room = li->start;
	while (room->link[++i])
	{
		if (room->link[i]->room->number == li->end->number)
		{
			li->data = li->data->begin;
			while (li->data)
			{
				ft_printf("%s\n", li->data->data);
				li->data = li->data->next;
			}
			ft_printf("\n");
			while (++cpt <= li->nb_ants)
				ft_printf("L%d-%s ", cpt, li->end->data[0]);
			ft_printf("\n");
			return (1);
		}
	}
	return (0);
}
