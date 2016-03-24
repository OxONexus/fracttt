/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 03:17:37 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 09:25:36 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_to_image(void *img, int x, int y, unsigned long color)
{
	t_img	pic;
	int		i;

	pic.data = mlx_get_data_addr(img, &pic.bpp, &pic.sizeline, &pic.endian);
	i = x * 4 + y * pic.sizeline;
	if (x >= 0 && y >= 0 && x <= 2000 && y <= 2000)
	{
		pic.data[i] = color % 256;
		color /= 256;
		pic.data[i + 1] = color % 256;
		color /= 256;
		pic.data[i + 2] = color % 256;
		color /= 256;
		pic.data[i + 3] = 0;
		color /= 256;
	}
}

void	clear_img(t_env *env, int color)
{
	int x;
	int y;

	x = 0;
	while (x < env->length)
	{
		y = 0;
		while (y < env->height)
		{
			mlx_pixel_put(env->mlx, env->ptr_win, x, y, 0x0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->ptr_win, env->img.img, 0, 0);
	printf("end\n");
}

void	draw_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->ptr_win, env->img.img, 0, 0);
}

int		get_color(int c)
{
	int color;

	color = 256 * 256 * (256 - sin(c) * 10) + 256 + (256 - cos(c))
		+ (256 - cos(c));
	return (color);
}
