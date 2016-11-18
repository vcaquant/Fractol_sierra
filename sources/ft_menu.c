/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:44:48 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/17 17:07:26 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	chose_fractal(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win_b);
	if (keycode == 126)
	{
		env->menu++;
		if (env->menu == 3)
			env->menu = 1;
		if (env->menu == 1)
			mlx_string_put(env->mlx, env->win_b, 380, 100, RED, "Julia");
		else if (env->menu == 2)
			mlx_string_put(env->mlx, env->win_b, 380, 150, A_F, "Mandelbrot");
	}
	if (keycode == 125)
	{
		env->menu--;
		if (env->menu == 0)
			env->menu = 2;
		if (env->menu == 1)
			mlx_string_put(env->mlx, env->win_b, 380, 100, RED, "Julia");
		else if (env->menu == 2)
			mlx_string_put(env->mlx, env->win_b, 380, 150, A_F, "Mandelbrot");
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
}
