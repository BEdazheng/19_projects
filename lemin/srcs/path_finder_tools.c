/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:52:16 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/22 18:28:59 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
**	Reset all room data of the graph to their initial state.
*/

void	reset(t_li *li)
{
	t_room	*room;

	room = li->start;
	while (room)
	{
		room->used = 0;
		room->dist = WEIGHT_MAX;
		room->queue = NULL;
		room->father = NULL;
		room = room->next;
	}
	li->start->dist = 0;
}

/*
**	create a set of room that will represent our path.
**	(cf. lem_in.h -> struct s_room_set)
*/

int		create_room_set(t_li *li, int j)
{
	int	i;

	i = 0;
	if (!(li->room_set_tmp =
		(t_room_set**)malloc(sizeof(t_room_set*) * (j + 2))))
		return (0);
	while (i < j + 2)
		li->room_set_tmp[i++] = NULL;
	return (1);
}
