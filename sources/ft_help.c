/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:25:49 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 23:04:46 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		aff_help_exit(int keycode, t_env *env)
{
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32mHelp Closed\033[0m\n");
		mlx_destroy_window(env->mlx, env->s_win);
		env->s_win = NULL;
	}
	return (0);
}

void	write_command(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 105, WHI,
		"M = activation du mouvement avec la souris");
	mlx_string_put(env->mlx, env->s_win, 0, 120, WHI,
		"< = Deplacement de la map vers la gauche");
	mlx_string_put(env->mlx, env->s_win, 0, 135, WHI,
		"^ = Deplacement de la map vers le haut");
	mlx_string_put(env->mlx, env->s_win, 0, 150, WHI,
		"v = Deplacement de la map vers le bas");
	mlx_string_put(env->mlx, env->s_win, 0, 215, WHI,
			"+ = Augmentation de l'iteration");
	mlx_string_put(env->mlx, env->s_win, 0, 230, WHI,
			"- = Diminution de l'iteration");
	mlx_string_put(env->mlx, env->s_win, 0, 295, WHI,
		"K = Augmentation des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 310, WHI, "M = Diminution des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 375, WHI,
		"I = Mettre ou enlever isometrie");
}

void	write_title1(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 0, ABS,
		" ===========================================");
	mlx_string_put(env->mlx, env->s_win, 0, 15, ABS,
		"|                    HELP                   |");
	mlx_string_put(env->mlx, env->s_win, 0, 30, ABS,
		" ===========================================");
	mlx_string_put(env->mlx, env->s_win, 0, 60, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 75, AZUR,
		"|            Variations             |");
	mlx_string_put(env->mlx, env->s_win, 0, 90, AZUR,
		" ===================================");
}

void	write_title2(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 170, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 185, AZUR,
		"|       Variations Iterations       |");
	mlx_string_put(env->mlx, env->s_win, 0, 200, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 250, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 265, AZUR,
		"|      Variations de la hauteur     |");
	mlx_string_put(env->mlx, env->s_win, 0, 280, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 330, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 345, AZUR,
		"|             Isometrie             |");
	mlx_string_put(env->mlx, env->s_win, 0, 360, AZUR,
		" ===================================");
}

void	aff_help(t_env *env)
{
	env->s_win = mlx_new_window(env->mlx, 450, 450, "HELP_FDF");
	write_command(env);
	write_title1(env);
	write_title2(env);
	mlx_key_hook(env->s_win, aff_help_exit, env);
}
