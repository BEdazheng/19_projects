/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:57:10 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/18 19:28:32 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;

	if (!lst)
		return (NULL);
	if (!(new_lst = (t_list*)malloc(sizeof(t_list*))))
		return (NULL);
	new_lst = f(lst);
	if (lst->next)
	{
		new_lst->next = ft_lstmap(lst->next, f);
		if (new_lst->next == NULL)
		{
			free(new_lst);
			return (NULL);
		}
	}
	else
		new_lst->next = NULL;
	return (new_lst);
}
