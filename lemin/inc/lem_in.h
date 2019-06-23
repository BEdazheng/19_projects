/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:23:50 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/23 14:13:21 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define WEIGHT_MAX 2147483647

typedef struct	s_data
{
	char			*data;
	struct s_data	*begin;
	struct s_data	*next;
}				t_data;

/*
**	data[0] = name
**	data[1] = x_coord
**	data[2] = y_coord
**	link = is use to know which others room are connect to the current one.
**	next = will allow to move on every room of the graph.
*/

typedef struct	s_room
{
	char			**data;
	int				dist;
	int				used;
	int				number;
	int				status;
	struct s_room	*father;
	struct s_room	*queue;
	struct s_link	**link;
	struct s_room	*next;
}				t_room;

/*
**	this structure represent the edge connected to each room.
**	room = indicate where the edge point to
**	reverse = indicate which room is the parent of this edge
*/

typedef struct	s_link
{
	t_room			*room;
	struct s_link	*reverse;
	int				dist;
	int				visited;
	int				src_status;
	int				dst_status;
}				t_link;
/*
**	A room_set is a linked list with each node pointing on a specific room
**	of the graph. This will be used to save a specific path.
**	Example : 	 Start	 Room5	 Room7	 Room3	 End	 NULL
**				roomset	->next	->next	->next	->next	->next
**
**	length = the length of each path.
**	ant_num	= the actual Ant number on the room.
**	prev = is the previous node inside the path.
**	next = to complicate to explain.
**	end = the last node of the path, so we can directly start from it.
*/

typedef struct	s_room_set
{
	int					length;
	int					ant_num;
	struct s_room		*room;
	struct s_room_set	*prev;
	struct s_room_set	*next;
	struct s_room_set	*end;
}				t_room_set;

/*
**	data = save all the data read on standard input.
**	nb_ants = the number of ants to move across the graph.
**	start_name & end_name = the name of the starting and ending room.
**	nb_start_end = count if we have exactly 1 start and 1 end.
**
**	tunnel_exist & reading_tunnel = tell if we found tunnel to read and if
**	we started to read tunnel. (used to manage error)
**
**	max_way = the max number of simultaneous path the pathfinder must look for.
**
**	nb_turns = store the max turns needed to send all ants.
**
**	tab_ants_per_path = how many ants we will send on each path.
**
**	start = the room where the graph start.
**	end = the room where the graph end.
**
**	room_set = is the list of the best simultaneous path we found.
**	room_set_tmp = will store the list of the path we are currently searching.
**				   and later compare it to the room_set and keep the best list.
*/

typedef struct	s_lem_in
{
	t_data				*data;
	long long			nb_ants;
	char				*start_name;
	char				*end_name;
	int					error;
	int					nb_start_end;
	int					tunnel_exist;
	int					reading_tunnel;
	int					max_way;
	int					nb_turns;
	int					*tab_ants_per_path;
	int					*tab_ants_per_path_tmp;
	t_room				*start;
	t_room				*end;
	t_room_set			**room_set;
	t_room_set			**room_set_tmp;
}				t_li;

/*
**	li_utils.c
*/

void			li_init(t_li *li);
t_li			*new_room(t_li *li, char **tab);
int				is_directly_linked(t_li *li);

/*
**	li_get_data.c
*/

void			li_get_data(t_li *li);

/*
**	li_check_data.c
*/

int				check_coordinate(t_li *li, char **tab);
int				check_is_link_or_room(char *line, char c);
void			check_error(t_li *li);

/*
**	manage_links.c
*/

int				parse_link(t_li *li, t_room *room1, t_room *room2, char **tab);

/*
**	path_finder.c
*/

int				solve(t_li *li);
void			reverse_edges(t_li *li, t_room *room);

/*
**	path_finder_fucntions.c
*/

void			bfs(t_li *li, t_room *queue, int i);
int				dijkstra(t_li *li);

/*
**	path_finder_tools.c
*/

void			reset(t_li *li);
int				create_room_set(t_li *li, int i);

/*
**	path_saver.c
*/

int				save_path(t_li *li, t_room *start, int cpt_path);

/*
**	get_best_set.c
*/

int				get_best_set(t_li *li, int nb_path);

/*
**	trashcan.c
*/

void			garbage_room(t_li *li);
void			garbage_list(t_room_set *list);
void			garbage_data(t_data *data);
void			garbage_roomset(t_room_set **set);
int				garbage_tab(char **tab);

#endif
