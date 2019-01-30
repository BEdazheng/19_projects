/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:27:27 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/20 09:47:45 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *save;

	tmp = *alst;
	while (tmp)
	{
		save = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = save;
	}
	*alst = NULL;
}
