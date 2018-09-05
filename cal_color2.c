/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:33:25 by jwu               #+#    #+#             */
/*   Updated: 2018/02/02 14:33:31 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			cal_h(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	i = -1;
	f->cr = -1.417022285618;
	f->ci = 0;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->cr;
		zi = 2 * tmp * zi + f->ci;
	}
	return (i);
}

int			cal_h2(int x, int y, t_fractol *f)
{
	double	tmp;
	double	zr;
	double	zi;
	int		i;

	zr = x / f->zoom + f->minx;
	zi = y / f->zoom + f->miny;
	i = -1;
	f->cr = -0.610435;
	f->ci = 0.001739;
	while (++i < f->iter && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->cr;
		zi = 3.3 * tmp * zi + f->ci;
	}
	return (i);
}
