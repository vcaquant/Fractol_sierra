/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:11:14 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 12:11:16 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_var(t_env *env)
{
	env->zoom = 1;
	env->x = 0;
	env->y = 0;
	env->it_max = 100;
	env->r = 12;
	env->g = 20;
	env->b = 16;
	env->move = 0;
	env->cr = 0.285;
	env->ci = 0.01;
	env->zr = 0;
	env->zi = 0;
	env->var_zr = 0;
	env->var_zi = 0;
}

int		ft_init_struct(t_env **env)
{
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->s_win = NULL;
	if (!((*env)->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	return (1);
}
