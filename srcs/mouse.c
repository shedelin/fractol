/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:50:59 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:51:02 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int keycode, int x, int y, t_env *e)
{
	if (keycode == 4)
	{
		e->iter += 1;
		e->xmin += (((double)x / WIDTH) * 0.1 * (e->xmax - e->xmin));
		e->xmax -= (((double)(WIDTH - x) / WIDTH) * 0.1 * (e->xmax - e->xmin));
		e->ymin += (((double)y / HEIGHT) * 0.1 * (e->ymax - e->ymin));
		e->ymax -= (((double)(HEIGHT - y) / HEIGHT) * .1 * (e->ymax - e->ymin));
	}
	if (keycode == 5)
	{
		if (e->iter != 0)
			e->iter -= 1;
		e->xmin -= (((double)x / WIDTH) * 0.1 * (e->xmax - e->xmin));
		e->xmax += (((double)(WIDTH - x) / WIDTH) * 0.1 * (e->xmax - e->xmin));
		e->ymin -= (((double)y / HEIGHT) * 0.1 * (e->ymax - e->ymin));
		e->ymax += (((double)(HEIGHT - y) / HEIGHT) * .1 * (e->ymax - e->ymin));
	}
	expose_hook(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if ((x >= 0) && (y >= 0) && (x < WIDTH) && (y < HEIGHT)
			&& e->lock == 1)
	{
		e->x2 = (double)x / 200;
		e->y2 = (double)y / 200;
		expose_hook(e);
	}
	return (0);
}
