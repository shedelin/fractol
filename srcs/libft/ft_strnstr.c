/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:17:48 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:17:50 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (n && *s1)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0 && ft_strlen(s2) <= n)
				return ((char *)s1);
		}
		n--;
		s1++;
	}
	return (NULL);
}
