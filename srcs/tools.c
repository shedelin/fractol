/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:51:18 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:51:20 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		usage(void)
{
	ft_putstr("Usage: ");
	ft_putendl("./fractol [num]\n1 - Mandelbrot \n2 - Julia-1");
	ft_putendl("3 - Julia-2 \n4 - Julia-3\n5 - Custom ./fractol 5 [num] [num]");
	exit (1);
}

void		put_pixel_to_img(t_env *e, int x, int y, int color)
{
	if ((y * e->x_max + 4 * x) < (e->x_max * HEIGHT) &&
			((y * e->x_max + 4 * x) >= 0) && ((x * 4) < e->x_max) && x >= 0)
	{
		e->data[y * e->x_max + 4 * x] = color;
		e->data[y * e->x_max + 4 * x + 1] = color >> 8;
		e->data[y * e->x_max + 4 * x + 2] = color >> 16;
	}
}

void		put_pixel(t_env *e, int x, int y, int color)
{
	if (e->i == IT_MAX + e->iter)
		put_pixel_to_img(e, x, y, 0);
	else
		put_pixel_to_img(e, x, y, color * e->i);
}

void		calcul(t_num *z, t_num *c, t_env *e)
{
	double	tmp;

	tmp = z->r;
	z->r = z->r * z->r - z->i * z->i + c->r;
	z->i = 2 * z->i * tmp + c->i;
	e->i++;
}
