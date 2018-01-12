/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:18:28 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:18:30 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	lens;
	size_t	i;

	i = 0;
	cpy = NULL;
	lens = ft_strlen(s);
	if (s)
	{
		if ((int)lens < 0 || len > lens || start > lens)
			return (NULL);
		if ((cpy = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		while (i < len)
			cpy[i++] = s[start++];
		cpy[i++] = '\0';
	}
	return (cpy);
}
