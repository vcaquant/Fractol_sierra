/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:51:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 15:52:07 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		findmandelbrot(t_env *env)
{
	double	tmp;
	int		i;

	i = 0;
	env->zr = 0 + env->var_zr;
	env->zi = 0 + env->var_zi;
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
	double	n;
	double	i;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	i = env->it_max / 2;
	env->it_sup = env->it_max - i;
    env->img_x = 800;
    env->img_y = 650;
	//env->img_x = (env->x2 - env->x1) * env->zoom;
	//env->img_y = (env->y2 - env->y1) * env->zoom;
	y = 0;
	while (y < env->img_y)
	{
		x = 0;
		while (x < env->img_x)
		{
			env->cr = maptoreal(x, env->img_x, env->x1, env->x2);
			env->ci = maptoimaginary(y, env->img_y, env->y1, env->y2);
			n = findmandelbrot(env);
			//if (n == env->it_max)
			//{
				ft_get_color(env, n, env->it_max);
				ft_pixel(env, x, y);
			/*}
			if (n == env->it_max - i)
			{
                env->r = 255;
				//env->r = 241;
				env->g = 0;
				env->b = 0;
                //ft_chose_color(env);
				ft_pixel(env, x, y);
			}
            else if (n == env->it_max - (i + 1))
			{
                env->b = 255;
				env->r = 0;
				//env->g = 196;
				env->g = 0;
                //ft_chose_color(env);
				ft_pixel(env, x, y);
			}*/
			x++;
		}
		y++;
	}
}
