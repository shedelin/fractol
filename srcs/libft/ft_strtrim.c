/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:18:38 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:18:40 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_end(char const *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (*s)
	{
		len--;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		{
			len--;
			i++;
		}
		return (i + 1);
	}
	return (0);
}

static size_t	ft_start(char const *s)
{
	size_t	start;

	start = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		start++;
		s++;
	}
	return (start);
}

char			*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	size_t	i;
	char	*cpy;

	start = ft_start(s);
	end = ft_end(s);
	if (end == start)
	{
		cpy = ft_strnew(start);
		ft_bzero(cpy, start);
	}
	else
	{
		cpy = ft_strnew(end - start);
		s = s + start;
		cpy = ft_strcpy(cpy, s);
		i = ft_strlen(cpy);
		while (end--)
			cpy[i--] = '\0';
	}
	return (cpy);
}
