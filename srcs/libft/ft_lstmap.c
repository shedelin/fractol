/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:02:41 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:02:42 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*origin;
	t_list	*prev;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	origin = new;
	prev = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (origin);
}
