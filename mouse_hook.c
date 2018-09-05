/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:37:51 by jwu               #+#    #+#             */
/*   Updated: 2018/01/20 14:37:52 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (y > 4)
	{
		x -= f->winx / 2;
		y -= f->winy / 2;
		if (button == 1 || button == 5)
		{
			f->zoom *= 1.3;
			f->iter += 2;
			f->minx += x / f->zoom / 0.6;
			f->maxx += x / f->zoom / 0.6;
			f->miny += y / f->zoom / 0.6;
			f->maxy += y / f->zoom / 0.6;
			pthread_draw(f);
		}
		else if (button == 2 || button == 4)
		{
			f->zoom *= 0.7;
			f->iter -= 2;
			pthread_draw(f);
		}
	}
	return (0);
}

int			motion(int x, int y, t_fractol *fractol)
{
	if (fractol->fractol != 1 && fractol->change == 1)
	{
		fractol->cr = fractol->minx + ((x * fractol->maxx) / fractol->winx);
		fractol->ci = fractol->miny + ((y * fractol->maxy) / fractol->winy);
		pthread_draw(fractol);
	}
	return (0);
}
