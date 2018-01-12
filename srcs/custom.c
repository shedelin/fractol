/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:49:14 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:49:15 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			custom(t_env *e, int color)
{
	double		x;
	double		y;
	t_num		c;
	t_num		z;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			e->i = 0;
			c.r = e->xmin + (x / WIDTH) * (e->xmax - e->xmin);
			c.i = e->ymin + (y / HEIGHT) * (e->ymax - e->ymin);
			z.r = e->custom_r * 0.1;
			z.i = e->custom_i * 0.1;
			while (z.r * z.r + z.i * z.i < 4 && e->i < IT_MAX + e->iter)
				calcul(&z, &c, e);
			put_pixel(e, x, y, color);
			y += 1;
		}
		x += 1;
	}
}
