/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:20:07 by jwu               #+#    #+#             */
/*   Updated: 2018/01/18 14:20:08 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "math.h"
# include "mlx.h"
# include <pthread.h>

# define MOTION_NOTIFY		6
# define PTR_MOTION_MASK	(1L << 6)

typedef struct		s_fractol
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*pixel_img;
	int				bpp;
	int				ed;
	int				s_line;
	int				fractol;
	int				winx;
	int				winy;
	int				r;
	int				g;
	int				b;
	double			zoom;
	double			iter;
	double			minx;
	double			miny;
	double			maxx;
	double			maxy;
	double			cr;
	double			ci;
	double			mx;
	double			my;
	int				y;
	int				ymax;
	int				nbthread;
	int				change;
	double			size;
}					t_fractol;

/*
** initialiation
*/
t_fractol			init_fractol(char *info);

/*
** draw
*/
void				put_pixel(int a, int b, t_fractol e, int color);
void				draw(t_fractol *f);
void				pthread_draw(t_fractol *f);

/*
** calcul de coulour dun pixel
*/
int					cal_julia(int x, int y, t_fractol *f);
int					cal_mandelbrot(int x, int y, t_fractol *f);
int					cal_hasard(int x, int y, t_fractol *f);
int					cal_hasard02(int x, int y, t_fractol *f);
int					cal_love(int x, int y, t_fractol *f);
int					cal_h(int x, int y, t_fractol *f);
int					cal_h2(int x, int y, t_fractol *f);
int					f_color(int i, t_fractol *f);

/*
** hook
*/
int					motion_active_hook(int keycode, t_fractol *f);
int					change_fractol_hook(int keycode, t_fractol *f);
int					init_hook(int keycode, t_fractol *f);
int					changec_hook(int keycode, t_fractol *f);
int					deplace_hook(int keycode, t_fractol *f);
int					key_hook(int keycode, t_fractol *f);
int					mouse_hook(int button, int x, int y, t_fractol *mlx);
int					motion(int x, int y, t_fractol *fractol);
int					mouse_hook(int button, int x, int y, t_fractol *f);

/*
** help
*/
int					is_correct(char *s);

#endif
