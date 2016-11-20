/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:20:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 22:47:57 by vcaquant         ###   ########.fr       */
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

int		aff_key(int keycode, t_env *env)
{
	ft_putstr("touche : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 4)
		too_much_help(env);
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ Fract_ol Closed\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 24 || keycode == 27)
		var_it(env, keycode);
	if (keycode == 15 || keycode == 5 || keycode == 11)
		ft_chose_color(env, keycode);
	if (keycode == 46)
	{
		if (env->move == 0)
			env->move++;
		else
			env->move--;
	}
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

int		key_menu(int keycode, t_env *env)
{
	ft_putstr("touche : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ Menu Closed\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode >= 123 && keycode <= 126)
		chose_fractal(env, keycode);
	if (keycode == 36)
		menu_enter(env);
	return (0);
}
