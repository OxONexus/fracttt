/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 08:39:41 by apaget            #+#    #+#             */
/*   Updated: 2016/03/30 16:37:14 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_env *env)
{
	if (key == MLX_KEY_ESC)
		exit(0);
	else if (key == MLX_KEY_UP)
		env->map.m.i += 0.3;
	else if (key == MLX_KEY_DOWN)
		env->map.m.i -= 0.3;
	else if (key == MLX_KEY_LEFT)
		env->map.m.r += 0.3;
	else if (key == MLX_KEY_RIGHT)
		env->map.m.r -= 0.3;
	else if (key == MLX_KEY_Z)
		env->map.max_it += 20;
	else if (key == MLX_KEY_A)
	{
		env->map.max_it = 20;
		env->map.m.r = 0;
		env->map.m.i = 0;
	}
	update(env);
	return (1);
}

int		click_hook(int button, int x, int y, t_env *env)
{
	if (x >= 0 && x <= env->length && y >= 0 && y <= env->height)
	{
		if (button == 5 || button == 1)
			env->map.zoom *= 1.3;
		else if (button == 4 || button == 2)
			env->map.zoom /= 1.3;
	}
	update(env);
	return (1);
}

int		expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->ptr_win, env->img.img, 0, 0);
	return (1);
}

int		mouse_hook(int x, int y, t_env *env)
{
	env->map.c.i = 1.5 * (y - (env->length / 2)) / (env->height *
			env->map.zoom / 2);
	env->map.c.r = 1.5 * (x - (env->height / 2)) / (env->height *
			env->map.zoom / 2);
	update(env);
	return (1);
}
