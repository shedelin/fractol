/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:49:37 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:49:38 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia3(t_env *e, int color)
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
			z.r = e->xmin + (x / WIDTH) * (e->xmax - e->xmin);
			z.i = e->ymin + (y / HEIGHT) * (e->ymax - e->ymin);
			c.r = -1.417022285618 * e->x2;
			c.i = 0.0099534 * e->y2;
			while (z.r * z.r + z.i * z.i < 4 && e->i < IT_MAX + e->iter)
				calcul(&z, &c, e);
			put_pixel(e, x, y, color);
			y += 1;
		}
		x += 1;
	}
}

void			julia2(t_env *e, int color)
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
			z.r = e->xmin + (x / WIDTH) * (e->xmax - e->xmin);
			z.i = e->ymin + (y / HEIGHT) * (e->ymax - e->ymin);
			c.r = -0.038088 * e->x2;
			c.i = 0.9754633 * e->y2;
			while (z.r * z.r + z.i * z.i < 4 && e->i < IT_MAX + e->iter)
				calcul(&z, &c, e);
			put_pixel(e, x, y, color);
			y += 1;
		}
		x += 1;
	}
}

void			julia(t_env *e, int color)
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
			z.r = e->xmin + (x / WIDTH) * (e->xmax - e->xmin);
			z.i = e->ymin + (y / HEIGHT) * (e->ymax - e->ymin);
			c.r = 0.285 * e->x2;
			c.i = 0.01 * e->y2;
			while (z.r * z.r + z.i * z.i < 4 && e->i < IT_MAX + e->iter)
				calcul(&z, &c, e);
			put_pixel(e, x, y, color);
			y += 1;
		}
		x += 1;
	}
}
