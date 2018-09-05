/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:55:24 by jwu               #+#    #+#             */
/*   Updated: 2018/01/20 14:55:24 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deplace_hook(int keycode, t_fractol *f)
{
	double	a;

	a = 50 / f->zoom;
	if (keycode == 123)
	{
		f->minx += a;
		f->maxx += a;
	}
	if (keycode == 124)
	{
		f->minx -= a;
		f->maxx -= a;
	}
	if (keycode == 125)
	{
		f->miny -= a;
		f->maxy -= a;
	}
	if (keycode == 126)
	{
		f->miny += a;
		f->maxy += a;
	}
	return (0);
}

int			changec_hook(int keycode, t_fractol *f)
{
	if (keycode == 15)
		f->r = (f->r + 1) % 50;
	if (keycode == 5)
		f->g = (f->g + 1) % 50;
	if (keycode == 11)
		f->b = (f->b + 1) % 50;
	return (0);
}

int			init_hook(int keycode, t_fractol *f)
{
	if (keycode == 49)
	{
		f->zoom = 150.0;
		f->iter = 50;
		f->minx = -2.2;
		f->miny = -2.2;
		f->maxx = 2.4;
		f->maxy = 2.4;
		f->cr = -0.70176;
		f->ci = -0.3842;
	}
	return (0);
}

int			change_fractol_hook(int keycode, t_fractol *f)
{
	if (keycode == 8)
	{
		f->zoom = 150.0;
		f->iter = 60;
		f->minx = -2.2;
		f->miny = -2.2;
		f->maxx = 2.4;
		f->maxy = 2.4;
		f->cr = -0.70176;
		f->ci = -0.3842;
		f->fractol = (f->fractol + 1) % 7;
	}
	return (0);
}
