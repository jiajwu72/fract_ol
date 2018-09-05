/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:56:37 by jwu               #+#    #+#             */
/*   Updated: 2018/01/19 17:56:39 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			cal_julia(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	i = -1;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->cr;
		zi = f->size * tmp * zi + f->ci;
	}
	return (i);
}

int			cal_mandelbrot(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = 0;
	zi = 0;
	i = -1;
	f->cr = x / f->zoom + f->minx;
	f->ci = y / f->zoom + f->miny;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->cr;
		zi = 2 * tmp * zi + f->ci;
	}
	return (i);
}

int			cal_love(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	i = -1;
	f->cr = 0.133913;
	f->ci = -1.845217;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = fabs(zr * zr - zi * zi) + f->cr;
		zi = (2 * tmp * zi) + f->ci;
	}
	return (i);
}

int			cal_hasard(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	f->cr = -0.8713;
	f->ci = 0.398261;
	i = -1;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = sin(zr * zr - zi * zi + f->cr);
		zi = 2 * tmp * zi + f->ci;
	}
	return (i);
}

int			cal_hasard02(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	f->cr = 0.36;
	f->ci = 0.074783;
	i = -1;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = sin(zr * zr - zi * zi + f->cr);
		zi = 3 * tmp * zi + f->ci;
	}
	return (i);
}
