/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:30:32 by jwu               #+#    #+#             */
/*   Updated: 2018/01/26 17:30:33 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_active_hook(int keycode, t_fractol *f)
{
	if (keycode == 0)
	{
		f->change = 1;
		mlx_hook(f->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion, f);
	}
	return (0);
}

int			motion_disactive_hook(int keycode, t_fractol *f)
{
	if (keycode == 2)
	{
		f->change = 0;
		mlx_hook(f->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion, f);
	}
	return (0);
}

int			grow(int keycode, t_fractol *f)
{
	if (keycode == 78)
		f->size += 0.1;
	else if (keycode == 69)
		f->size -= 0.1;
	return (0);
}

int			key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
	{
		ft_putendl("Au revoir");
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	deplace_hook(keycode, f);
	init_hook(keycode, f);
	changec_hook(keycode, f);
	change_fractol_hook(keycode, f);
	motion_active_hook(keycode, f);
	motion_disactive_hook(keycode, f);
	grow(keycode, f);
	pthread_draw(f);
	return (0);
}
