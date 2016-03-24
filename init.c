/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:52:34 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 08:41:02 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_map(t_env *env)
{
	env->map.max_it = 20;
	env->map.zoom = 1;
	env->map.pos.x = 0;
	env->map.pos.y = 0;
	env->map.c.i = 0;
	env->map.c.r = 2;
	env->map.m.i = 0;
	env->map.m.r = 0;
}

int		init_env(t_env *env, char *name)
{
	env->length = 1000;
	env->height = 1000;
	env->mlx = NULL;
	env->ptr_win = NULL;
	if ((env->mlx = mlx_init()) == NULL)
		return (-1);
	if ((env->ptr_win = mlx_new_window(env->mlx, env->length,env->height, name)) == NULL)
		return (-1);
	if ((env->img.img = mlx_new_image(env->mlx, env->length,
					env->height)) == NULL)
		return (-1);
	if ((env->img.data = mlx_get_data_addr(env->img.img, &(env->img.bpp),
					&(env->img.sizeline), &(env->img.endian))) == NULL)
		return (-1);
	init_map(env);
	return (1);
}
