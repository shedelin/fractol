/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 17:58:59 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 17:59:01 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		sign;

	sign = 0;
	num = 0;
	if (*str)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		sign = (str[i] == '-' && ft_isalpha(str[i + 1]) == 0) ? -1 : 1;
		if ((str[i] == '+' || str[i] == '-')
				&& (str[i + 1] <= '9' && str[i + 1] >= '0'))
			i++;
		while (((ft_isdigit(str[i])) && str[i]) || (str[i] == '\\'))
		{
			if (str[i] < '0' || str[i] > '9')
				return (num * sign);
			num = (str[i] - '0') + num * 10;
			i++;
		}
	}
	return (num * sign);
}
