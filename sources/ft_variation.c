/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:04:09 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 18:04:11 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	var_it(t_env *env, int keycode)
{
	if (env->menu == 1)
	{
		if (keycode == 24)
			env->it_max += 2.5;
		else if (keycode == 27)
			env->it_max -= 2.5;
	}
	else if (env->menu == 2)
	{
		if (keycode == 24)
			env->it_max += 2;
		else if (keycode == 27)
			env->it_max -= 2;
	}
	else
	{
		if (keycode == 24)
			env->it_max += 2;
		else if (keycode == 27)
			env->it_max -= 2;
	}
	draw_frct(env);
}
