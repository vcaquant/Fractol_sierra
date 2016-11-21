/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:20:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 10:55:41 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	too_much_help(t_env *env)
{
	if (env->s_win == NULL)
	{
		ft_putstr("\033[0;33mOpen Help\033[0m\n");
		aff_help(env);
	}
	else
	{
		mlx_string_put(env->mlx, env->win, 0, 0, RED,
			"Help it's already open");
		ft_putstr("\033[31m✖︎ You can't open other HELP\033[0m\n");
	}
}

void	zoom(t_env *env, int keycode)
{
	if (keycode == 24)
		env->zoom += 10;
	else if (keycode == 27)
		env->zoom -= 10;
	draw_frct(env);
}

void	move(t_env *env, int keycode)
{
	if (keycode == 126)
		env->y -= 50 / env->zoom;
	else if (keycode == 125)
		env->y += 50 / env->zoom;
	else if (keycode == 123)
		env->x += 50 / env->zoom;
	else if (keycode == 124)
		env->x -= 50 / env->zoom;
	draw_frct(env);
}

void	act_move(t_env *env)
{
	if (env->move == 0)
		env->move++;
	else
		env->move--;
}

int		aff_key(int keycode, t_env *env)
{
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		move(env, keycode);
	if (keycode == 4)
		too_much_help(env);
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ Fract_ol Closed\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 15 || keycode == 5 || keycode == 11)
		ft_chose_color(env, keycode);
	if (keycode == 8)
		ft_change_color(env);
	if (keycode == 24 || keycode == 27)
		var_it(env, keycode);
	if (keycode == 46)
		act_move(env);
	if (keycode == 29)
	{
		init_var(env);
		draw_frct(env);
	}
	if (keycode == 3)
		close_win_open_menu(env);
	return (0);
}
