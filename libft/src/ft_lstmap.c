/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:50:39 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 12:34:09 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!(begin = malloc(sizeof(t_list))))
		return (NULL);
	if (!lst)
		return (NULL);
	new = f(lst);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
