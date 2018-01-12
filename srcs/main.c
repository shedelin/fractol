/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:49:57 by shedelin          #+#    #+#             */
/*   Updated: 2015/05/29 19:45:23 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../minilibx_macos/mlx.h"

void	check_arg(char **av)
{
	if (ft_strlen(av[1]) == 1)
	{
		if (!ft_isdigit(*av[1]))
			usage();
	}
	else
		usage();
	if (*av[1] < '1' || *av[1] > '5')
		usage();
}

void	launch_fractol(char **av)
{
	t_env	e;

	make_env(&e);
	if (*av[1] == '1')
		e.num = 1;
	if (*av[1] == '2')
		e.num = 2;
	if (*av[1] == '3')
		e.num = 3;
	if (*av[1] == '4')
		e.num = 4;
	if (*av[1] == '5')
	{
		e.custom_r = ft_atoi(av[2]);
		e.custom_i = ft_atoi(av[3]);
		e.num = 5;
	}
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_hook(e.win, 2, 1, &key_press_event, &e);
	if (e.num == 2 || e.num == 3 || e.num == 4)
		mlx_hook(e.win, 6, 7, &mouse_move, &e);
	mlx_mouse_hook(e.win, &mouse_event, &e);
	mlx_loop(e.mlx);
}

void	launch_process(char **av)
{
	check_arg(av);
	launch_fractol(av);
}

int		main(int ac, char **av)
{
	if ((ac == 1 || (ac > 2 && *av[1] == '5' && ac != 4) ||
				(ac == 2 && *av[1] == '5')))
		usage();
	else
		launch_process(av);
	return (0);
}
