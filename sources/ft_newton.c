/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:01 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 21:59:03 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_newton(t_env *env)
{
    double  i;
    double  j;
    double  tmp;
    int     x;
    int     y;
    double  xx;
    double  yy;
    double  dx;
    double  dy;
    int     count;
    double  d;

    dx = (env->x2 - env->x1) / W_X;
    dy = (env->y2 - env->y1) / W_Y;
    env->x1 = -2.0;
	env->x2 = 2.0;
	env->y1 = -2.0;
	env->y2 = 2.0;
	//i = env->it_max / 2;
    env->img_x = 800;
    env->img_y = 650;
    i = 0;
    while (i < W_X)
    {
        j = 0;
        while (j < W_Y)
        {
            x = env->x1 + i * dx;
            y = env->y1 + i * dy;
            count = 0;
            while (count < env->it_max)
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
                ft_pixel(env, i, j);
            j++;
        }
        i++;
    }
}
