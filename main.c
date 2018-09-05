/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:02:04 by jwu               #+#    #+#             */
/*   Updated: 2018/01/18 16:16:01 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol		init_fractol(char *info)
{
	t_fractol	f;

	f.fractol = ft_atoi(info);
	f.size = 2;
	f.zoom = 150.0;
	f.iter = 100;
	f.minx = -2.2;
	f.miny = -2.2;
	f.maxx = 2.4;
	f.maxy = 2.4;
	f.cr = -0.70176;
	f.ci = -0.3842;
	f.r = 0;
	f.g = 0;
	f.b = 2;
	f.y = 0;
	f.nbthread = 32;
	f.mlx = mlx_init();
	f.winx = (f.maxx - f.minx) * f.zoom;
	f.winy = (f.maxy - f.miny) * f.zoom;
	f.win = mlx_new_window(f.mlx, f.winx, f.winy, "FDF");
	f.img = mlx_new_image(f.mlx, f.winx, f.winy);
	f.pixel_img = mlx_get_data_addr(f.img, &(f.bpp),
									&(f.s_line), &(f.ed));
	return (f);
}

void			help(void)
{
	ft_putendl("------------------------------------------------");
	ft_putendl("MANUEL:");
	ft_putendl("change color:			r g b");
	ft_putendl("move:				up down left right");
	ft_putendl("change fractal:			c");
	ft_putendl("initialisation:			space");
	ft_putendl("zoom in/out:			mouse left/right");
	ft_putendl("change size of fractal:		+/-");
	ft_putendl("-------------------------------------------------");
}

void			msg(void)
{
	ft_putendl("usage: ./fractol \"0/1/2/3/4/5/6\"");
	ft_putendl("0:		julia");
	ft_putendl("1:		Mandelbot");
	ft_putendl("2:		fractol d\'invention 1");
	ft_putendl("3:		fractol d\'invention 2");
	ft_putendl("4:		fractol de plein de coeur");
	ft_putendl("2:		fractol d\'invention 3");
	ft_putendl("3:		fractol d\'invention 4");
}

int				expose_hook(t_fractol *f)
{
	if (f->fractol < 7)
		pthread_draw(f);
	return (0);
}

int				main(int ac, char **av)
{
	t_fractol data;

	if (ac != 2 || ft_atoi(av[1]) > 6 || is_correct(av[1]) == 0)
		msg();
	else
	{
		help();
		data = init_fractol(av[1]);
		mlx_expose_hook(data.win, expose_hook, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_loop(data.mlx);
		mlx_destroy_window(data.mlx, data.win);
	}
	return (1);
}
