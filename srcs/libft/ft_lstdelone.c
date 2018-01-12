/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:02:16 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:02:18 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ltr;

	if (!alst || !*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ltr = (*alst)->next;
	free(*alst);
	(*alst)->next = ltr;
	*alst = NULL;
}
