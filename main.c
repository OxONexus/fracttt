/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 06:00:24 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 08:33:16 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_env env;
	if (argc == 2)
	{
		init_env(&env, argv[1]);
		get_fractal(argv[1], &env);
		mlx_put_image_to_window(env.mlx, env.ptr_win, env.img.img, 0, 0);
		mlx_key_hook(env.ptr_win, key_hook, &env);
		mlx_expose_hook(env.ptr_win, expose_hook, &env);
		mlx_mouse_hook(env.ptr_win, click_hook, &env);
		mlx_hook(env.ptr_win, 6, (1L << 6), mouse_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		write(1, "Usage : ./fractol [NAME]\n\tAvailable : julia, Mandelbrot, ??", 59);
	return 0;
}
