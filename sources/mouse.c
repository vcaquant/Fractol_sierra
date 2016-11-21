/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:11:04 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 11:11:07 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	x -= W_X / 2;
	y -= W_Y / 2;
	if (button == 4)
	{
		env->zoom *= 2.1;
		env->x += x / env->zoom / 0.21;
		env->y -= y / env->zoom / 0.21;
	}
	else if (button == 5 && env->zoom > 2)
		env->zoom /= 2.1;
	if (button == 4 || button == 5)
		draw_frct(env);
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{
	if (env->move == 1)
	{
		if (env->menu == 1)
		{
			x -= W_X / 2;
			y -= W_Y / 2;
			env->cr = ((float)x / W_X) * 2;
			env->ci = ((float)y / W_Y) * 2;
		}
		else if (env->menu == 2 || env->menu == 3)
		{
			x -= W_X / 2;
			y -= W_Y / 2;
			env->var_zr = ((float)x / W_X) * 2;
			env->var_zi = ((float)y / W_Y) * 2;
		}
		draw_frct(env);
	}
	return (0);
}
