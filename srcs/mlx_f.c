/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:50:35 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:50:36 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>

static void	key_press_event2(int keycode, t_env *e)
{
	if (keycode == RIGHT)
	{
		e->xmax -= 0.05 * (e->xmax - e->xmin);
		e->xmin -= 0.05 * (e->xmax - e->xmin);
	}
	if (keycode == UP)
	{
		e->ymax += 0.05 * (e->xmax - e->xmin);
		e->ymin += 0.05 * (e->xmax - e->xmin);
	}
	if (keycode == DOWN)
	{
		e->ymax -= 0.05 * (e->xmax - e->xmin);
		e->ymin -= 0.05 * (e->xmax - e->xmin);
	}
	if (keycode == 37)
	{
		if (e->lock)
			e->lock = 0;
		else
			e->lock = 1;
	}
}

int			key_press_event(int keycode, t_env *e)
{
	(void)e;
	if (keycode == ESC)
		exit (1);
	if (keycode == PAD_1)
		e->color *= 5;
	if (keycode == PAD_2)
		e->color = 5644865;
	if (keycode == PAD_3)
		e->color = 756427777;
	if (keycode == PAD_4)
		e->color = 48888988;
	if (keycode == LEFT)
	{
		e->xmax += 0.05 * (e->xmax - e->xmin);
		e->xmin += 0.05 * (e->xmax - e->xmin);
	}
	key_press_event2(keycode, e);
	expose_hook(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	ft_bzero(e->data, e->x_max * HEIGHT);
	if (e->num == 1)
		mandelbrot(e, e->color);
	else if (e->num == 2)
		julia(e, e->color);
	else if (e->num == 3)
		julia2(e, e->color);
	else if (e->num == 4)
		julia3(e, e->color);
	else if (e->num == 5)
		custom(e, e->color);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void		make_env(t_env *e)
{
	e->color = 0x456456;
	e->move_x = 0;
	e->iter = 0;
	e->lock = 1;
	e->move_y = 0;
	e->y2 = 0;
	e->xmin = -2;
	e->xmax = 2;
	e->ymin = -2;
	e->ymax = 2;
	e->x2 = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fractol");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->x_max, &e->endian);
}
