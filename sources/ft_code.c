/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:20:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 18:20:56 by vcaquant         ###   ########.fr       */
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

void	var_it(t_env *env, int keycode)
{
	if (env->menu == 1)
	{
		if (keycode == 40)
			env->it_max += 2.5;
		else if (keycode == 46)
			env->it_max -= 2.5;
	}
	else
	{
		if (keycode == 40)
			env->it_max += 2;
		else if (keycode == 46)
			env->it_max -= 2;
	}
	draw_frct(env);
}

void 	var_c(t_env *env, int key)
{
	if (key == 17)
	{
		env->cr += 0.1;
		draw_frct(env);
	}
	if (key == 5)
	{
		env->cr -= 0.1;
		draw_frct(env);
	}
	if (key == 3)
	{
		env->ci += 0.1;
		draw_frct(env);
	}
	if (key == 38)
	{
		env->ci -= 0.1;
		draw_frct(env);
	}
}

void 	var_z(t_env *env, int key)
{
	if (key == 17)
	{
		env->var_zr += 0.1;
		draw_frct(env);
	}
	if (key == 5)
	{
		env->var_zr -= 0.1;
		draw_frct(env);
	}
	if (key == 3)
	{
		env->var_zi += 0.1;
		draw_frct(env);
	}
	if (key == 38)
	{
		env->var_zi -= 0.1;
		draw_frct(env);
	}
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
	//if (keycode == 38 || keycode == 46)
	//	draw_frct(env);
	if (keycode == 24 || keycode == 27)
		zoom(env, keycode);
	if (keycode == 40 || keycode == 46)
		var_it(env, keycode);
	if (keycode == 17 || keycode == 5 || keycode == 3 || keycode == 38)
	{
		if (env->menu == 1)
			var_c(env, keycode);
		else
			var_z(env, keycode);
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
	/*{
		mlx_destroy_window(env->mlx, env->win_b);
		ft_putstr("\033[0;32m✔︎ Menu Closed\033[0m\n");
		prp_win(env);
		ft_mandelbrot(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}*/
		chose_fractal(env, keycode);
	if (keycode == 36)
		menu_enter(env);
	return (0);
}
