/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:01:27 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:01:28 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_countlen(int n)
{
	int				i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				i;
	unsigned int	n2;
	char			sign;
	char			*str;

	n2 = (unsigned int)n;
	sign = '+';
	i = ft_countlen(n2);
	str = ft_strnew(i);
	str[i] = '\0';
	if (n2 == 0)
		str[0] = '0';
	if (n < 0)
	{
		n2 *= -1;
		sign = '-';
	}
	while (i)
	{
		str[--i] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	if (sign == '-')
		str[i] = '-';
	return (str);
}
