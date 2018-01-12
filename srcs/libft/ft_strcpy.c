/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:11:10 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:11:12 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	cur;

	cur = 0;
	while (src[cur] != '\0')
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = '\0';
	return (dst);
}
