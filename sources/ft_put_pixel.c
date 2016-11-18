/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:38:23 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/17 16:38:27 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel2(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = 185;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = 128;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = 41;
	}
}

void	ft_pixel(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = 0;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = 0;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = 0;
	}
}

void	ft_pixel3(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = 200;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = 200;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = 200;
	}
}

void	ft_pixel4(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = 220;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = 220;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = 220;
	}
}

void	ft_pixel5(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = 255;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = 255;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = 255;
	}
}
