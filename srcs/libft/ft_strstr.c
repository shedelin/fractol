/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:18:15 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:18:17 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
