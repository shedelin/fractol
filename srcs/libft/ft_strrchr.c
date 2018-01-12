/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:23:55 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:23:56 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	cc;
	int		i;

	ptr = NULL;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		cc = *s;
		if (cc == c)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}
