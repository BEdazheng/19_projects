/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:52:02 by dazheng           #+#    #+#             */
/*   Updated: 2019/01/24 13:51:41 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void	garbage(t_li *li)
{
	free(li->tab_ants_per_path);
	garbage_room(li);
	garbage_roomset(li->room_set);
	garbage_data(li->data);
}

/*
**	We know the maximum number of turns needed to travel all ants from the
**	start to the end.
**	So for each turn we will browse the first room of each path that follow
**	the starting room, and give give each the ant_number++.
**	If we have 3 paths the first will get the ant number 1
**					   the second will get the ant number 2
**					   the third will get the ant number 3 ...
**
**	When the first room of each used path got their ant, we will start from
**	the last room of each path, print the ant number and the room name if
**	an ant is present.
**
**	Then will give that room the ant number the previous room.
**	example : S-a-b-E
**	S = start, a = first room, E = end.
**
**	- We start giving 'a' the ant number 1;
**	- Then we go to the E and check if there is an ant, no, so we give the end
**	room the ant number of 'b' which is actually 0;
**	- Same for 'b', but the ant number of 'a' is 1, so now the ant number of 'b'
**	is also '1';
**	- Now we restart, increase cpt_turns by 1, setting it to turn number 2.
**	- we give 'a' the ant number '2';
**	- We go to the end, print is an ant exist, set ant_number to 'b' so '1';
**	- Then we print the ant number of 'b' and set 'b' to 'a' so '2';
**	- Print 'a' ant and name, restart, etc... Until we reach the max turns.
*/

static void	print_soluce(t_li *li, int cpt_ants, int cpt_turns, int i)
{
	t_room_set	**room_set_tmp;
	t_room_set	*tmp;

	room_set_tmp = li->room_set;
	i = -1;
	while (++cpt_turns <= li->nb_turns)
	{
		i = -1;
		while (room_set_tmp[++i])
			room_set_tmp[i]->next->ant_num = (li->tab_ants_per_path[i]-- > 0)
				? cpt_ants++ : 0;
		i = -1;
		while (room_set_tmp[++i])
		{
			tmp = room_set_tmp[i]->end;
			while (tmp->prev)
			{
				if (tmp->ant_num != 0)
					printf("L%d-%s ", tmp->ant_num, tmp->room->data[0]);
				tmp->ant_num = tmp->prev->ant_num;
				tmp = tmp->prev;
			}
		}
		printf("\n");
	}
}

/*
**	Print all the data read from the file
*/

static void	print_data(t_li *li)
{
	li->data = li->data->begin;
	while (li->data)
	{
		printf("%s\n", li->data->data);
		li->data = li->data->next;
	}
	printf("\n");
	print_soluce(li, 1, 0, 0);
}

int			main(int ac, char **av)
{
	t_li	li;

	if (ac == 1 && av)
	{
		li_init(&li);
		li_get_data(&li);
		if (li.nb_start_end != 2 || li.error == 1 || !li.start->link ||
				!li.end->link)
			printf("ERROR\n");
		else if (is_directly_linked(&li) == 0)
		{
			while (li.start->link[li.max_way] && li.end->link[li.max_way])
				li.max_way++;
			(solve(&li) == 0) ? print_data(&li) : printf("ERROR\n");
		}
		garbage(&li);
	}
	else
		printf("ERROR\n");
	return (0);
}
