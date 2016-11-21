/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/21 10:12:47 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		red_cross(void)
{
	ft_putstr("\033[0;32m✔︎ Fract_ol Closed\033[0m\n");
	exit(EXIT_SUCCESS);
}

void	prp_win(t_env *env)
{
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "Fract_ol");
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_hook(env->win, 4, (1L << 2), mouse_hook, env);
	mlx_hook(env->win, 6, (1L << 6), mouse_move, env);
	mlx_hook(env->win, 17, (1L << 17), red_cross, env);
}

void	exc_param(t_env *env, char av)
{
	if (av == 'J')
	{
		env->menu = 1;
		prp_win(env);
		ft_julia(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	else if (av == 'M')
	{
		env->menu = 2;
		prp_win(env);
		ft_mandelbrot(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	else if (av == 'B')
	{
		env->menu = 3;
		prp_win(env);
		ft_burningship(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
	}
	else if (av == 'F')
		menu(env);
}

int		ft_param(void)
{
	ft_putstr("\n                   ===============\n");
	ft_putstr("                  |    Fractol    |\n");
	ft_putstr("                   ===============\n");
	ft_putstr("\nSyntax : ./fractol <param>\n");
	ft_putstr("\nParamaters :\n");
	ft_putstr("J : for excute Julia\n");
	ft_putstr("M : for excute Mandelbrot\n");
	ft_putstr("B : for excute Burning-ship\n");
	ft_putstr("F : for excute Menu chose fractal\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac > 2 || ac < 2 || (av[1][0] != 'J' && av[1][0] != 'M' &&
		av[1][0] != 'B' && av[1][0] != 'F') || ft_strlen(av[1]) != 1)
		return (ft_param());
	if (!ft_init_struct(&env))
		return (-1);
	init_var(env);
	env->menu = 0;
	env->mlx = mlx_init();
	exc_param(env, av[1][0]);
	mlx_loop(env->mlx);
	return (0);
}
