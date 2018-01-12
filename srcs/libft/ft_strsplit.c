/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:18:03 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:18:04 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strcreate(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = ft_strnew(i);
	i = 0;
	while (*s != c && *s != '\0')
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}

static size_t	ft_nextword(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static size_t	ft_yalloc(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			len++;
		}
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;

	tab = NULL;
	if (s)
	{
		j = 0;
		if (!(tab = (char **)malloc(sizeof(char *) * ft_yalloc(s, c) + 1)))
			return (NULL);
		while (*s)
		{
			if (*s != c)
			{
				tab[j] = ft_strcreate((char *)s, c);
				s = s + ft_strlen(tab[j++]);
			}
			s = s + ft_nextword((char *)s, c);
		}
		tab[j] = NULL;
	}
	return (tab);
}
