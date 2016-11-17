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
	if (keycode == 38 || keycode == 46)
		draw_frct(env, keycode);
	return (0);
}

int		key_menu(int keycode, t_env *env)
{
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_clear_window(env->mlx, env->win_b);
		if (keycode == 123)
		{
			mlx_string_put(env->mlx, env->win_b, 500, 200, WHI, "Julia");
			env->menu = 1;
		}
		if (keycode == 124)
		{
			mlx_string_put(env->mlx, env->win_b, 500, 250, WHI, "Mandelbrot");
			env->menu = 2;
		}
	}
	if (keycode == 36)
	{
		if (env->menu == 1)
		{
			mlx_destroy_window(env->mlx, env->win_b);
			prp_win(env);
			Julia(env);
			mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
		}
		else if (env->menu == 2)
		{
			mlx_destroy_window(env->mlx, env->win_b);
			prp_win(env);
			Mandelbrot(env);
			mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
		}
		else
			mlx_string_put(env->mlx, env->win_b, 300, 400, WHI, "Veuillez choisir une fractal");
	}
	return (0);
}
