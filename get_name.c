/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 06:14:55 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 08:51:07 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void		update(t_env *env)
{
	if (env->type == JULIA)
		julia(env);
	else if (env->type == MALBORORORO)
		mandelbrot(env);
	//clear_img(env, 0x0);
	mlx_put_image_to_window(env->mlx, env->ptr_win, env->img.img, 0, 0);
}

void		get_fractal(char *str, t_env *env)
{
	if (!ft_strcmp(str, "julia"))
		env->type = JULIA;
	else if (!ft_strcmp(str, "mandelbrot"))
		env->type = MALBORORORO;
	else
	{
		write(1, "Usage : ./fractol [NAME]\n\tAvailable : julia, Mandelbrot, ??", 59);
		mlx_destroy_image(env->mlx, env->img.img);
		exit(0);
	}
	update(env);
}
