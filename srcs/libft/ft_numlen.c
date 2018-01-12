/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:07:07 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:07:09 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_numlen(int num)
{
	unsigned int		size;

	size = 1;
	if (num < 0)
	{
		num = -num;
		size++;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}
