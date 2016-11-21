/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:51:15 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 08:24:46 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		findjulia(t_env *env)
{
	double	tmp;
	int		i;

	i = 0;
	while ((env->zr * env->zr + env->zi * env->zi) <= 4 &&
			i < env->it_max)
	{
		tmp = env->zr * env->zr - env->zi * env->zi + env->cr;
		env->zi = 2 * env->zi * env->zr + env->ci;
		env->zr = tmp;
		i++;
	}
	return (i);
}

void	ft_julia(t_env *env)
{
	int		x;
	int		y;
	int		n;
	int		color;

	env->x1 = -1;
	env->x2 = 1;
	env->y1 = -1.2;
	env->y2 = 1.2;
	y = 0;
	while (y++ < W_Y)
	{
		x = 0;
		while (x++ < W_X)
		{
			env->zr = maptoreal(env, x);
			env->zi = maptoimaginary(env, y);
			n = findjulia(env);
			color = ((255 - n * env->r) << 16) + ((255 - n * env->g) << 8) +
				(255 - n * env->b);
			if (n != env->it_max)
				ft_pixel(env, x, y, color);
		}
	}
}
