/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:01 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 17:56:49 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_newton(t_env *env)
{
	double	i;
	double	j;
	double	tmp;
	int		x;
	int		y;
	double	xx;
	double	yy;
	int		count;
	double	d;

	env->img_x = (env->x2 - env->x1) / W_X;
	env->img_y = (env->y2 - env->y1) / W_Y;
	env->x1 = -2.0;
	env->x2 = 2.0;
	env->y1 = -2.0;
	env->y2 = 2.0;
	i = 0;
	while (i < W_Y)
	{
		j = 0;
		while (j < W_X)
		{
			x = env->x1 + i * env->img_x;
			y = env->y1 + i * env->img_y;
			count = 0;
			while (count < env->it_max || (3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy)) < 4)
			{
				xx = x * x;
				yy = y * y;
				d = 3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
				if (d == 0.0)
					d = 0.000001;
				tmp = x;
				x = (2 / 3) * x + (xx - yy) / d;
				y = (2 / 3) * y - 2 * tmp * y / d;
				count++;
			}
			env->r = 255;
			env->g = 255;
			env->b = 255;
			if (count == env->it_max)
				ft_pixel(env, j, i);
			j++;
		}
		i++;
	}
}
