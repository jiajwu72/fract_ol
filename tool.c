/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:31:27 by jwu               #+#    #+#             */
/*   Updated: 2018/02/01 14:31:32 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_correct(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

int		f_color(int i, t_fractol *f)
{
	int		red;
	int		green;
	int		blue;

	if (i == f->iter)
		return (0);
	red = cos(i + f->r) * 128 * 128 * 128;
	green = cos(i + f->g) * 128 * 128;
	blue = cos(i + f->b) * 128;
	return (red + green + blue);
}
