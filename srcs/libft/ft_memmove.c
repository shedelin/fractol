/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:06:38 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:06:40 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(len);
	tmp = ft_strncpy(tmp, src, len);
	dst = (void *)ft_strncpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
