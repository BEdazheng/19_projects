/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:45:05 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 15:25:06 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
**	This file contains all functions used to free all the memory used inside
**	the program.
*/

int				garbage_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (0);
}

void			garbage_room(t_li *li)
{
	t_room	*tmp;
	int		i;

	free(li->start_name);
	free(li->end_name);
	while (li->start)
	{
		tmp = li->start->next;
		garbage_tab(li->start->data);
		i = -1;
		while (li->start->link && li->start->link[++i])
			free(li->start->link[i]);
		free(li->start->link);
		free(li->start);
		li->start = tmp;
	}
}

void			garbage_roomset(t_room_set **set)
{
	t_room_set	*next;
	t_room_set	*temp;
	int			i;

	i = 0;
	if (!set)
		return ;
	while (set[i])
	{
		temp = set[i];
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		i++;
	}
	free(set);
}

void			garbage_list(t_room_set *list)
{
	t_room_set	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void			garbage_data(t_data *data)
{
	t_data	*tmp;

	while (data)
	{
		free(data->data);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}
