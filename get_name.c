/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 06:14:55 by apaget            #+#    #+#             */
/*   Updated: 2016/03/30 16:29:28 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		lauch_thread(t_env *env, void *fct);

void		update(t_env *env)
{
	if (env->type == JULIA)
		lauch_thread(env, &julia);
	else if (env->type == MALBORORORO)
		lauch_thread(env, &mandelbrot);
	else if (env->type == BURNING)
		lauch_thread(env, &burningship);
	mlx_put_image_to_window(env->mlx, env->ptr_win, env->img.img, 0, 0);

}

void		lauch_thread(t_env *env, void *fct)
{
	int i;
	pthread_t	tid[4];
	t_arg		args[4];

	i = 0;
	while (i < 4)
	{
		args[i].from = i * (env->height / 4);
		args[i].to = (i + 1) * (env->height / 4);
		args[i].env = env;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_create(&tid[i], NULL, fct, &args[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}

void		get_fractal(char *str, t_env *env)
{
	if (!ft_strcmp(str, "julia"))
		env->type = JULIA;
	else if (!ft_strcmp(str, "mandelbrot"))
		env->type = MALBORORORO;
	else if (!ft_strcmp(str, "burningship"))
		env->type = BURNING;
	else
	{
		ft_putstr("Usage : ./fractol [NAME]\n\tAvailable : julia, Mandelbrot, burning");
		mlx_destroy_image(env->mlx, env->img.img);
		exit(0);
	}
	update(env);
}

void		apply_pos(t_env *env, int *i)
{
	pixel_put_to_image(env->img.img, i[0] + env->map.pos.x, i[1]
			+ env->map.pos.y, get_color(i[2]) | 0xFF);
}
