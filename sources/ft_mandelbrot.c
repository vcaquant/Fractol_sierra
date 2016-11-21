/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:51:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 08:25:07 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		findmandelbrot(t_env *env, int x, int y)
{
	double	tmp;
	int		i;

	i = 0;
	env->zr = 0 + env->var_zr;
	env->zi = 0 + env->var_zi;
	env->cr = 1.5 * (x - W_X / 2) / (0.5 * env->zoom * W_X)
		+ (env->x / W_X / 1.37) - 0.5;
	env->ci = (y - W_Y / 2) / (0.5 * env->zoom * W_Y) - (env->y / W_Y / 1.92);
	while ((env->zr * env->zr + env->zi * env->zi) < 4 &&
			i < env->it_max)
	{
		tmp = env->zr * env->zr - env->zi * env->zi + env->cr;
		env->zi = 2 * env->zi * env->zr + env->ci;
		env->zr = tmp;
		i++;
	}
	return (i);
}

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;
	int		n;
	int		i;
	int		color;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	i = env->it_max / 2;
	y = 0;
	while (y++ < W_Y)
	{
		x = 0;
		while (x++ < W_X)
		{
			n = findmandelbrot(env, x, y);
			color = ((255 - n * env->r) << 16) + ((255 - n * env->g) << 8) +
				(255 - n * env->b);
			if (n != env->it_max)
				ft_pixel(env, x, y, color);
		}
	}
}
