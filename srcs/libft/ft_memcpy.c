/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:03:49 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:03:50 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr;
	const char	*ptr2;

	ptr = dest;
	ptr2 = src;
	while (n > 0)
	{
		*ptr++ = *ptr2++;
		n--;
	}
	return (dest);
}
