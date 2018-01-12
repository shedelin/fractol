/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:39:31 by shedelin          #+#    #+#             */
/*   Updated: 2015/04/21 15:39:34 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# define WIDTH 600
# define HEIGHT 600
# define IT_MAX 15
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PAD_1 83
# define PAD_2 84
# define PAD_3 85
# define PAD_4 86
# define PAD_5 87
# define PAD_6 88
# define ESC 53

typedef struct		s_num
{
	double			r;
	double			i;
}					t_num;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				x_max;
	int				endian;
	int				num;
	int				color;
	double			move_x;
	double			move_y;
	double			xmax;
	double			ymax;
	double			xmin;
	double			ymin;
	double			x2;
	double			y2;
	int				iter;
	int				lock;
	int				i;
	double			custom_r;
	double			custom_i;
}					t_env;

int					expose_hook(t_env *e);
void				make_env(t_env *e);
void				mandelbrot(t_env *e, int color);
void				julia(t_env *e, int color);
void				julia2(t_env *e, int color);
void				julia3(t_env *e, int color);
void				custom(t_env *e, int color);
void				usage(void);
void				put_pixel_to_img(t_env *e, int x, int y, int color);
void				put_pixel(t_env *e, int x, int y, int color);
void				calcul(t_num *z, t_num *c, t_env *e);
int					mouse_event(int keycode, int x, int y, t_env *e);
int					mouse_move(int x, int y, t_env *e);
int					key_press_event(int keycode, t_env *e);

#endif
