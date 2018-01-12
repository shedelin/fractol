/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:02:03 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:02:05 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ltr;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		ltr = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = ltr;
	}
	*alst = NULL;
}
