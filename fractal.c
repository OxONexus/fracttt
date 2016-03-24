/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 09:06:28 by apaget            #+#    #+#             */
/*   Updated: 2016/03/24 09:54:12 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int burning_color(t_reel *c0, t_reel *c1, t_reel *c2, int max_it)
{
	int i;

	i = 0;
	while (++i < max_it)
	{
		c1->r = fabs(c1->r);
		c1->i = fabs(c1->i);
		c2->r = c1->r * c1->r - c1->i * c1->i + c0->r;
		c1->i = 2 * c1->r * c1->i + c0->i;
		c1->r = c2->r;
		if (c1->r * c1->r + c1->i * c1->i > 4)
			break ;
	}
	return (i);
}

void burningship(t_env *env)
{
	t_reel c[3];
	int i[3];

	i[1] = -1;
	while (++i[1] < env->height)
	{
		i[0] = -1;
		while (++i[0] < env->length)
		{
			c[0].r = 2 * (i[0] - env->height / 2) /
				(env->height * env->map.zoom / 2) + env->map.m.i;
			c[0].i = 2.5 * (i[1] - env->length / 2) /
				(env->length * env->map.zoom / 2) + env->map.m.r;
			c[1].i = 0.0;
			c[1].r = 0.0;
			pixel_put_to_image(env->img.img, i[0] + env->map.pos.x, i[1] + env->map.pos.y,get_color(burning_color(&c[0], &c[1], &c[2], env->map.max_it)));
		}
	}
}

void			julia(t_env *env)
{
	t_reel	c[2];
	int		i[3];

	i[1] = -1;
	while (++i[1] < env->height)
	{
		i[0] = -1;
		while (++i[0] < env->length)
		{
			c[0].r = 1.5 * (i[0] - env->length / 2) / (env->length *
					env->map.zoom / 2) + env->map.m.i;
			c[0].i = 1.5 * (i[1] - env->height / 2) / (env->height *
					env->map.zoom / 2) + env->map.m.r;
			i[2] = 0;
			while (++i[2] < env->map.max_it)
			{
				c[1] = c[0];
				c[0].r = c[1].r * c[1].r - c[1].i * c[1].i + env->map.c.r;
				c[0].i = 2 * c[1].r * c[1].i + env->map.c.i;
				if (c[0].r * c[0].r + c[0].i * c[0].i > 4)
					break ;
			}
			apply_pos(env, i);
		}
	}
}

unsigned int	get_manderbrot_color(t_reel *a, t_reel *b, t_reel *c,
		int max_iter)
{
	int i;

	i = 0;
	while (++i < max_iter)
	{
		c->r = b->r * b->r - b->i * b->i + a->r;
		b->i = 2 * b->r * b->i + a->i;
		b->r = c->r;
		if (b->r * b->r + b->i * b->i > 4)
			break ;
	}
	return (i);
}

void			mandelbrot(t_env *env)
{
	t_reel	c[3];
	int		i[3];

	i[1] = 0;
	while (++i[1] < env->height)
	{
		i[0] = -1;
		while (++i[0] < env->length)
		{
			c[0].r = 1.7 * (i[0] - env->length / 2) /
				(env->height * env->map.zoom / 2) + env->map.m.i;
			c[0].i = 1.7 * (i[1] - env->height / 2) /
				(env->length * env->map.zoom / 2) + env->map.m.r;
			c[1].i = 0.0;
			c[1].r = 0.0;
			pixel_put_to_image(env->img.img, i[0] + env->map.pos.x, i[1] +
					env->map.pos.y, get_color(get_manderbrot_color(&c[0], &c[1],
							&c[2], env->map.max_it)));
		}
	}
}
