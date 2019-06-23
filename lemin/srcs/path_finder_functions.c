/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:25:29 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 15:36:51 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		queue_push_back(t_room **queue, t_room *room)
{
	t_room *tmp;

	if (!(*queue))
		*queue = room;
	else
	{
		tmp = *queue;
		while (tmp->queue)
			tmp = tmp->queue;
		tmp->queue = room;
	}
}

static t_room	*dequeue_front(t_room **queue)
{
	t_room *tmp;

	tmp = (*queue);
	(*queue) = (*queue)->queue;
	return (tmp);
}

/*
**	https://en.wikipedia.org/wiki/Breadth-first_search
**	fix all room dist to minimum found dist to get the shortest path at the end
*/

void			bfs(t_li *li, t_room *queue, int i)
{
	t_room	*tmp;

	li->start->used = 1;
	queue_push_back(&queue, li->start);
	while (queue)
	{
		tmp = dequeue_front(&queue);
		i = -1;
		while (tmp->link[++i])
		{
			if (!tmp->link[i]->room->used && !tmp->link[i]->visited)
			{
				if (tmp->status == 1 && tmp->link[i]->dst_status != 2)
					continue ;
				if (tmp->dist + tmp->link[i]->dist < tmp->link[i]->room->dist)
				{
					tmp->link[i]->room->used = 1;
					tmp->link[i]->room->status = tmp->link[i]->dst_status;
					tmp->link[i]->room->dist = tmp->dist + tmp->link[i]->dist;
					tmp->link[i]->room->father = tmp;
					queue_push_back(&queue, tmp->link[i]->room);
				}
			}
		}
	}
}

/*
**	Get an unused room with the minimum dist
*/

static t_room	*get_room_min_dist(t_li *li)
{
	int		min;
	t_room	*save;
	t_room	*room;

	save = NULL;
	room = li->start;
	min = 2147483647;
	while (room)
	{
		if (room->used == 0)
		{
			if (room->dist < min)
			{
				min = room->dist;
				save = room;
			}
		}
		room = room->next;
	}
	return (save);
}

/*
**	start by fixing start dist to 0;
**	when calling get_room_min_dist, it will first return the Starting room
**	because it's the only room with a dist different than MAX DIST
**
**	Then this will fix all next node with a min_dist of current_min_dist + 1
**	example : Start->R1->R6->R7->END
**			  Start will get min_dist = 0
**			  R1 = Start_min_dist + 1 = 1
**			  R6 = R1_min_dist + 1 = 2 etc...
**	and so on for each link of each room : Start->R1 = 1
**										   Start->R2 = 1
**										   Start->R3 = 1
**	This will also set the father room of each link to the current room.
**	When all link to the room got a distance, it set the current room as used.
**	And look for an other room.
*/

int				dijkstra(t_li *li)
{
	t_room	*tmp;
	int		i;

	li->start->dist = 0;
	while (1)
	{
		i = -1;
		tmp = get_room_min_dist(li);
		if (!tmp || tmp->number == li->end->number)
			break ;
		i = -1;
		while (tmp->link[++i])
		{
			if (!tmp->link[i]->room->used)
			{
				if (tmp->link[i]->room->dist > tmp->dist + 1)
				{
					tmp->link[i]->room->dist = tmp->dist + 1;
					tmp->link[i]->room->father = tmp;
				}
			}
		}
		tmp->used = 1;
	}
	return (li->end->father == NULL ? 0 : 1);
}
