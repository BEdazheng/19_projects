/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 03:05:17 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 10:20:47 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int		link_realloc(t_room *room, t_link *link)
{
	t_link	**new_link;
	int		i;

	i = 0;
	new_link = NULL;
	if (room->link)
	{
		while (room->link[i])
			i++;
		if (!(new_link = (t_link**)malloc(sizeof(t_link*) * (i + 2))))
			return (0);
		i = -1;
		while (room->link[++i])
			new_link[i] = room->link[i];
		free(room->link);
		room->link = new_link;
	}
	else if (!(room->link = (t_link**)malloc(sizeof(t_link*) * 2)))
		return (0);
	room->link[i++] = link;
	room->link[i] = NULL;
	return (1);
}

static int		create_link(t_room *room1, t_room *room2)
{
	t_link	*link1;
	t_link	*link2;

	if (!(link1 = (t_link*)malloc(sizeof(t_link))) ||
		!(link2 = (t_link*)malloc(sizeof(t_link))))
		return (0);
	link1->room = room2;
	link1->reverse = link2;
	link1->dist = 1;
	link1->visited = 0;
	link1->src_status = 0;
	link1->dst_status = 0;
	link2->room = room1;
	link2->reverse = link1;
	link2->dist = 1;
	link2->visited = 0;
	link2->src_status = 0;
	link2->dst_status = 0;
	if (!link_realloc(room1, link1) || !link_realloc(room2, link2))
		return (0);
	return (1);
}

static t_room	*find_room(t_li *li, char *name)
{
	t_room	*room;

	room = li->start;
	while (room)
	{
		if (ft_strcmp(room->data[0], name) == 0)
			return (room);
		room = room->next;
	}
	return (NULL);
}

static int		link_exist(t_room *room1, t_room *room2)
{
	int	i;

	i = 0;
	if (room1->number == room2->number)
		return (0);
	while (room1->link && room1->link[i])
	{
		if (room1->link[i]->room->number == room2->number)
			return (0);
		i++;
	}
	return (1);
}

int				parse_link(t_li *li, t_room *room1, t_room *room2, char **tab)
{
	if (tab[0] != NULL && tab[1] != NULL && tab[2] == NULL)
	{
		room1 = find_room(li, tab[0]);
		room2 = find_room(li, tab[1]);
		garbage_tab(tab);
		if (room1 == NULL || room2 == NULL)
			return (0);
		li->reading_tunnel = 1;
		if (link_exist(room1, room2) == 0)
			return (1);
		if (create_link(room1, room2) == 0)
			return (0);
	}
	else
		return (garbage_tab(tab));
	return (1);
}
