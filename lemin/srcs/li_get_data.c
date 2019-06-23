/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 01:26:39 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/24 12:37:34 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
**	This is use to save all data read inside a structure to print them later
**	if we found a solution to the graph.
*/

static int	save_data(t_li *li, char *line)
{
	if (!li->data)
	{
		if (!(li->data = (t_data*)malloc(sizeof(t_data))))
			return (0);
		li->data->data = line;
		li->data->begin = li->data;
		li->data->next = NULL;
	}
	else
	{
		if (!(li->data->next = (t_data*)malloc(sizeof(t_data))))
			return (0);
		li->data->next->data = line;
		li->data->next->begin = li->data->begin;
		li->data->next->next = NULL;
		li->data = li->data->next;
	}
	return (1);
}

/*
**	Save the data into the li structure depending if it's a room or tunnel
**	this will also check if the data are valid.
*/

static int	get_room_or_link(t_li *li, char *line)
{
	char	**tab;
	t_room	*room1;
	t_room	*room2;

	room1 = NULL;
	room2 = NULL;
	if (check_is_link_or_room(line, '-') != -1)
	{
		li->tunnel_exist = 1;
		check_error(li);
		tab = ft_strsplit(line, '-');
		return (parse_link(li, room1, room2, tab));
	}
	else if (check_is_link_or_room(line, ' ') != -1 && li->reading_tunnel == 0)
	{
		tab = ft_strsplit(line, ' ');
		if ((tab && (!tab[0] || !tab[1] || tab[2] == NULL || tab[3] != NULL ||
			check_coordinate(li, tab) == 0)))
			return (garbage_tab(tab));
		return (1);
	}
	return (0);
}

/*
**	if the command found was giving the room where the graph start
**	or where the graph end. This will save the name of theses room
**	for further use.
*/

static int	get_start_end(t_li *li, int start_end)
{
	int		i;
	char	**tab;
	char	*line;

	i = 0;
	tab = NULL;
	get_next_line(0, &line);
	if (line && (line[0] == 'L' || line[0] == '#' || !save_data(li, line)))
	{
		free(line);
		return (0);
	}
	tab = ft_strsplit(line, ' ');
	if (tab && (!tab[0] || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL))
		return (garbage_tab(tab));
	if (start_end == 1)
		li->start_name = ft_strdup(tab[0]);
	else
		li->end_name = ft_strdup(tab[0]);
	if (check_coordinate(li, tab) == 0)
		return (0);
	return (1);
}

/*
**	if a command was found this check what kind of command it is.
*/

static void	handle_command(t_li *li, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (li->start_name != NULL || get_start_end(li, 1) == 0)
			li->error = 1;
		li->nb_start_end++;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (li->end_name != NULL || get_start_end(li, 2) == 0)
			li->error = 1;
		li->nb_start_end++;
	}
}

/*
**	Skip all kind all comments or commands that would appear before
**	the number of ants,
**	then get the number of ants,
**	read the data and handle command
**	if it's not a command or commentary get the room or link.
*/

void		li_get_data(t_li *li)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) && line && (line[0] == '#' ||
												line[0] == 'L'))
	{
		save_data(li, line);
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0 ||
			line[0] == 'L')
			return ;
	}
	li->error = (ft_strcmp(ft_atoi2(line, &li->nb_ants), "error") == 0
				|| li->nb_ants <= 0) ? 1 : 0;
	save_data(li, line);
	while (li->error == 0 && get_next_line(0, &line))
	{
		save_data(li, line);
		if (line && line[0] == '#')
			handle_command(li, line);
		else if (!line || line[0] == 'L' || get_room_or_link(li, line) == 0)
			li->error = 1;
	}
	if (li->tunnel_exist == 0)
		li->error = 1;
}
