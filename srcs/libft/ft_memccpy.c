/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:17 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:03:20 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr;
	char	*ptr2;

	ptr = (char *)dst;
	ptr2 = (char *)src;
	while (n--)
	{
		if (*ptr2 == c)
		{
			*ptr++ = *ptr2++;
			return (ptr);
		}
		*ptr++ = *ptr2++;
	}
	return (NULL);
}
