/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:44:56 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 09:51:31 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_key.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>

typedef struct			s_img
{
	unsigned int		width;
	unsigned int		height;
	int					bpp;
	int					sizeline;
	int					color;
	int					endian;
	void				*img;
	char				*data;
}						t_img;

typedef struct			s_reel
{
	double				i;
	double				r;
}						t_reel;

typedef struct			s_pt
{
						int x;
						int y;
}						t_pt;

typedef struct			s_map
{
	int					max_it;
	double				zoom;
	t_pt				pos;
	t_reel				m;
	t_reel				c;
}						t_map;

typedef struct			s_env
{
	char				type;
	void				*mlx;
	void				*ptr_win;
	void				(*f)(struct s_env *env);
	int					length;
	int					height;
	t_img				img;
	t_map				map;
}						t_env;

void					julia(t_env *env);
void					mandelbrot(t_env *env);
int						init_env(t_env *env, char *name);
int						key_hook(int key, t_env *env);
int						expose_hook(t_env *env);
void					pixel_put_to_image(void *img, int x, int y,
		unsigned long color);
int						get_color(int c);
int						mouse_hook(int x, int y, t_env *env);
int						click_hook(int button, int x, int y, t_env *env);
void					update(t_env *env);
void					get_fractal(char *str, t_env *env);
void					clear_img(t_env *env, int color);
void					apply_pos(t_env *env, int *i);
void					burningship(t_env *env);

#endif
