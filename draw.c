/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:38:49 by jwu               #+#    #+#             */
/*   Updated: 2018/01/18 15:47:26 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(int a, int b, t_fractol e, int color)
{
	int			i;

	i = (a * 4) + (b * e.s_line);
	e.pixel_img[i] = color;
	e.pixel_img[++i] = color >> 8;
	e.pixel_img[++i] = color >> 16;
}

void			drawline(int *p1, int *p2, int color, t_fractol *f)
{
	double		dd;
	double		x;
	double		y;
	double		dx;
	double		dy;

	x = p1[0];
	y = p1[1];
	dx = p2[0] - x;
	dy = p2[1] - y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- > 0)
	{
		put_pixel(x, y, *f, color);
		x += dx;
		y += dy;
	}
}

int				def_color(int x, int tmp, t_fractol *f)
{
	int			color;

	color = 0;
	if (f->fractol == 0)
		color = cal_julia(x, tmp, f);
	else if (f->fractol == 1)
		color = cal_mandelbrot(x, tmp, f);
	else if (f->fractol == 2)
		color = cal_hasard(x, tmp, f);
	else if (f->fractol == 3)
		color = cal_hasard02(x, tmp, f);
	else if (f->fractol == 4)
		color = cal_love(x, tmp, f);
	else if (f->fractol == 5)
		color = cal_h(x, tmp, f);
	else if (f->fractol == 6)
		color = cal_h2(x, tmp, f);
	color = f_color(color, f);
	return (color);
}

void			draw(t_fractol *f)
{
	int			color;
	int			x;
	int			tmp;

	x = -1;
	tmp = f->y;
	while (tmp < f->ymax)
	{
		while (++x < f->winx)
		{
			color = def_color(x, tmp, f);
			put_pixel(x, tmp, *f, color);
		}
		x = 0;
		tmp++;
	}
}

void			pthread_draw(t_fractol *f)
{
	t_fractol	tab[f->nbthread];
	pthread_t	t[f->nbthread];
	int			i;
	int			ret;

	i = -1;
	while (++i < f->nbthread)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_fractol));
		tab[i].y = (f->winx / f->nbthread) * i;
		tab[i].ymax = (f->winy / f->nbthread) * (i + 1);
	}
	i = -1;
	while (++i < f->nbthread)
	{
		if ((ret = pthread_create(&t[i], NULL, (void *)draw, &tab[i])))
		{
			ft_putendl("thread create error!");
			exit(0);
		}
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
