/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:38:23 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 09:11:26 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_chose_color(t_env *env, int key)
{
	if (key == 15)
	{
		env->r = 90;
		env->g = 255;
		env->b = 255;
		draw_frct(env);
	}
	if (key == 5)
	{
		env->r = 255;
		env->g = 90;
		env->b = 255;
		draw_frct(env);
	}
	if (key == 11)
	{
		env->r = 255;
		env->g = 255;
		env->b = 90;
		draw_frct(env);
	}
}

void	ft_change_color(t_env *env)
{
	if (env->g == 90)
	{
		env->r -= 10;
		env->b -= 15;
	}
	if (env->r == 90)
	{
		env->g -= 10;
		env->b -= 15;
	}
	if (env->b == 90)
	{
		env->r -= 10;
		env->g -= 15;
	}
	draw_frct(env);
}

void	ft_pixel(t_env *env, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < W_Y && x < W_X)
	{
		env->img->bts_img[(y * env->img->size_line) +
			((env->img->bpp / 8) * x) + 2] = r;
		env->img->bts_img[(y * env->img->size_line) +
			((env->img->bpp / 8) * x) + 1] = g;
		env->img->bts_img[(y * env->img->size_line) +
			((env->img->bpp / 8) * x)] = b;
	}
}

void	draw_frct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	if (env->menu == 1)
		ft_julia(env);
	else if (env->menu == 2)
		ft_mandelbrot(env);
	else
		ft_burningship(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}
