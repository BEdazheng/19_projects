/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:31:39 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 10:53:22 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int	check_room_already_exist(t_li *li, char **tab)
{
	t_room	*tmp;

	if (li->start == NULL)
		li = new_room(li, tab);
	else
	{
		tmp = li->start;
		while (tmp)
		{
			if (ft_strcmp(tmp->data[0], tab[0]) == 0)
			{
				li->error = 1;
				return (0);
			}
			tmp = tmp->next;
		}
		li = new_room(li, tab);
	}
	return (1);
}

/*
**	check if coordinate are correct
*/

int			check_coordinate(t_li *li, char **tab)
{
	long long	x;
	long long	y;

	x = 0;
	y = 0;
	return (check_room_already_exist(li, tab) == 0 ||
			ft_strcmp(ft_atoi2(tab[1], &x), "error") == 0 ||
			ft_strcmp(ft_atoi2(tab[2], &y), "error") == 0) ? 0 : 1;
}

int			check_is_link_or_room(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	if (line[i])
		return (i);
	return (-1);
}

/*
**	fix the start and end room in the li structure.
**	This allow to jump direcetly to the starting or ending room of the graph
**	without browsing all the linked_list
*/

static void	check_n_replace(t_li *li)
{
	t_room	*start;
	t_room	*tmp;

	tmp = li->start;
	if (ft_strcmp(tmp->data[0], li->start_name) != 0)
	{
		while (ft_strcmp(tmp->next->data[0], li->start_name) != 0)
			tmp = tmp->next;
		start = tmp->next;
		tmp->next = start->next;
		start->next = li->start;
		li->start = start;
		tmp = li->start;
	}
	if (ft_strcmp(li->end->data[0], li->end_name) != 0)
	{
		while (ft_strcmp(tmp->next->data[0], li->end_name) != 0)
			tmp = tmp->next;
		li->end = tmp->next;
	}
}

void		check_error(t_li *li)
{
	if (li->nb_start_end != 2)
		li->error = 1;
	if (li->error == 0 && (ft_strcmp(li->end->data[0], li->end_name) != 0 ||
			ft_strcmp(li->start->data[0], li->start_name) != 0))
		check_n_replace(li);
}
