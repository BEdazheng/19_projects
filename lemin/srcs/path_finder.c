/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:44:47 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/24 13:50:32 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
**	If the father is null this mean there is no way at all, so nothing to
**	reverse.
**	Else get the father of the last room (should be the end room)
**	and so this will start searchin in the "s_link structure" the corresponding
**	room.
**	IN-OUT(dst_status) follow link
**	http://www.macfreek.nl/memory/Disjoint_Path_Finding
**
**	Reverse->visited = 1 : make the link unidirecitonnal
*/

static void	do_end(t_li *li, t_room *room)
{
	t_room	*tmp;
	int		i;

	if (!(tmp = room->father))
		return ;
	i = -1;
	while (room->link[++i])
	{
		if (room->link[i]->room->number == tmp->number)
		{
			room->link[i]->dst_status = 2;
			room->link[i]->dist = -1;
			room->link[i]->reverse->visited = 1;
		}
	}
	reverse_edges(li, tmp);
}

/*
**	room->link[i]->reverse->visited = 1 :
**	set the reverse->visited (starting_room) to 1, to not re-use this way.
*/

static void	do_start(t_room *room)
{
	t_room	*tmp;
	int		i;

	i = -1;
	tmp = room->father;
	while (room->link[++i])
	{
		if (room->link[i]->room->number == tmp->number)
		{
			room->link[i]->src_status = 1;
			room->link[i]->dist = -1;
			room->link[i]->reverse->visited = 1;
			room->link[i]->visited = 0;
		}
		else if (!room->link[i]->visited)
		{
			room->link[i]->src_status = 2;
			room->link[i]->reverse->dst_status = 1;
		}
	}
}

/*
**	tmp = room->father : will follow the path from end to start.
**	this will reverse all link following the path to make them unidirectionnal,
**	and setting all their dist to -1, this will be usefull when using
**	superposition.
**	Until it reach the starting_room, it will call do_start : cf. do_end.
*/

void		reverse_edges(t_li *li, t_room *room)
{
	t_room	*tmp;
	int		i;

	i = -1;
	if (room->number == li->end->number)
		return (do_end(li, room));
	tmp = room->father;
	if (tmp->number == li->start->number)
		return (do_start(room));
	while (room->link[++i])
	{
		if (room->link[i]->room->number == tmp->number)
		{
			room->link[i]->src_status = 1;
			room->link[i]->dst_status = 2;
			room->link[i]->dist = -1;
			room->link[i]->reverse->visited = 1;
		}
		else if (!room->link[i]->visited)
		{
			room->link[i]->src_status = 2;
			room->link[i]->reverse->dst_status = 1;
		}
	}
	reverse_edges(li, tmp);
}

static void	set_length(t_li *li)
{
	t_room_set	*tmp;
	int			i;
	int			j;

	i = 0;
	while (li->room_set_tmp[i])
	{
		tmp = li->room_set_tmp[i];
		j = 0;
		while (tmp)
		{
			tmp = tmp->next;
			j++;
		}
		li->room_set_tmp[i]->length = j - 1;
		i++;
	}
}

int			solve(t_li *li)
{
	int	i;

	i = 0;
	if (!dijkstra(li))
		return (0);
	reverse_edges(li, li->end);
	if (!create_room_set(li, i) || !save_path(li, li->start, 0))
		return (0);
	set_length(li);
	if (!get_best_set(li, i + 1))
		return (0);
	while (++i < li->max_way)
	{
		reset(li);
		bfs(li, NULL, 0);
		reverse_edges(li, li->end);
		if (li->end->father == NULL)
			break ;
		if (!create_room_set(li, i) || !save_path(li, li->start, 0))
			return (0);
		set_length(li);
		if (!get_best_set(li, i + 1))
			break ;
	}
	return (li->error);
}
