/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:05:08 by mikorale          #+#    #+#             */
/*   Updated: 2018/06/15 19:18:12 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;
	t_list *tmp_next;

	tmp = *alst;
	while (tmp)
	{
		tmp_next = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp_next;
	}
	*alst = NULL;
}
