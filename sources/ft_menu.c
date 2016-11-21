/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:44:48 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 12:13:12 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	chose_fractal(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win_b);
	if (keycode == 125)
	{
		env->menu++;
		if (env->menu >= 4)
			env->menu = 1;
		if (env->menu == 1)
			mlx_string_put(env->mlx, env->win_b, 170, 100, RED, "Julia");
		else if (env->menu == 2)
			mlx_string_put(env->mlx, env->win_b, 150, 150, A_F, "Mandelbrot");
		else if (env->menu == 3)
			mlx_string_put(env->mlx, env->win_b, 140, 200, ABS, "Burning ship");
	}
	if (keycode == 126)
	{
		env->menu--;
		if (env->menu <= 0)
			env->menu = 3;
		if (env->menu == 1)
			mlx_string_put(env->mlx, env->win_b, 170, 100, RED, "Julia");
		else if (env->menu == 2)
			mlx_string_put(env->mlx, env->win_b, 150, 150, A_F, "Mandelbrot");
		else if (env->menu == 3)
			mlx_string_put(env->mlx, env->win_b, 140, 200, ABS, "Burning ship");
	}
}

void	menu_enter(t_env *env)
{
	if (env->menu == 1)
	{
		mlx_destroy_window(env->mlx, env->win_b);
		ft_putstr("\033[0;32m✔︎ Menu Closed\033[0m\n");
		prp_win(env);
		ft_julia(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	else if (env->menu == 2)
	{
		mlx_destroy_window(env->mlx, env->win_b);
		ft_putstr("\033[0;32m✔︎ Menu Closed\033[0m\n");
		prp_win(env);
		ft_mandelbrot(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	else if (env->menu == 3)
	{
		mlx_destroy_window(env->mlx, env->win_b);
		ft_putstr("\033[0;32m✔︎ Menu Closed\033[0m\n");
		prp_win(env);
		ft_burningship(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
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

void	menu(t_env *env)
{
	env->win_b = mlx_new_window(env->mlx, 400, 400, "MENU");
	mlx_hook(env->win_b, 2, 0, key_menu, env);
	mlx_hook(env->win_b, 17, (1L << 17), red_cross, env);
}

void	close_win_open_menu(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	init_var(env);
	menu(env);
}
