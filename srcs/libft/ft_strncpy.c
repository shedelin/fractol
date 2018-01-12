/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:16:47 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:16:50 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	cur;

	cur = 0;
	while (cur < n && src[cur])
	{
		dst[cur] = src[cur];
		cur++;
	}
	while (cur < n)
	{
		dst[cur] = '\0';
		cur++;
	}
	return (dst);
}
