/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:38:23 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 17:48:24 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_chose_color(t_env *env, int key)
{
	if (key == 15)
	{
		if (env->modul_r > 5)
			env->modul_r -= 5;
	}
	else if (key == 5)
	{
		if (env->modul_g > 5)
			env->modul_g -= 5;
	}
	else if (key == 11)
	{
		if (env->modul_b > 5)
			env->modul_b -= 5;
	}
	else if (env->modul_r == 5 && env->modul_g == 5 && env->modul_b == 5)
	{
		env->modul_r = 255;
		env->modul_g = 255;
		env->modul_b = 255;
	}
	draw_frct(env);
}

void	ft_get_color(t_env *env, double z1, double z2)
{
	int	z;

	if (z1 > z2)
		z = z1 - ((z1 - z2) / 2);
	else if (z1 < z2)
		z = z2 - ((z2 - z1) / 2);
	else
		z = z1;
	env->r = ((z + env->rand + env->red) % env->modul_r);
	env->g = ((z + env->rand + env->green) % env->modul_g);
	env->b = ((z + env->rand + env->blue) % env->modul_b);
}

void	ft_pixel(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;
	/*if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bts_img[(4 * (x + env->img->size_line / 4 * y))] = env->b;
		env->img->bts_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = env->g;
		env->img->bts_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = env->r;
	}*/
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < W_Y && x < W_X)
	{
		env->img->bts_img[(y * env->img->size_line) + ((env->img->bpp / 8) * x) + 2] = r;
		env->img->bts_img[(y * env->img->size_line) + ((env->img->bpp / 8) * x) + 1] = g;
		env->img->bts_img[(y * env->img->size_line) + ((env->img->bpp / 8) * x)] = b;
	}
}
