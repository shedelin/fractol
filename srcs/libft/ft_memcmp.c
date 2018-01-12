/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:22:58 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 18:22:59 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_;
	const unsigned char	*s2_;

	s1_ = s1;
	s2_ = s2;
	while (n--)
	{
		if (*s1_ != *s2_)
			return (*s1_ - *s2_);
		s1_++;
		s2_++;
	}
	return (0);
}
