/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/17 17:08:18 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		red_cross(void)
{
	ft_putstr("\033[0;32m✔︎ Fract_ol Closed\033[0m\n");
	exit(EXIT_SUCCESS);
}

int		ft_init_struct(t_env **env)
{
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->s_win = NULL;
	if (!((*env)->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	(*env)->zoom = 1;
	(*env)->x = 0;
	(*env)->y = 0;
	(*env)->it_max = 100;
	(*env)->rand = 30;
	(*env)->red = 50;
	(*env)->green = 50;
	(*env)->blue = 50;
	(*env)->modul_r = 255;
	(*env)->modul_g = 255;
	(*env)->modul_b = 255;
	(*env)->r = 6;
	(*env)->g = 2;
	(*env)->b = 10;
	(*env)->move = 0;
	return (1);
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	x -= W_X / 2;
	y -= W_Y / 2;
	if (button == 5)
	{
		env->zoom *= 1.1;
		env->x += (float)x / env->zoom / 2.51;
		env->y -= (float)y / env->zoom / 2.51;
	}
	else if (button == 4 && env->zoom > 1)
		env->zoom /= 1.1;
	if (button == 4 || button == 5)
		draw_frct(env);
	return (0);
}


void	prp_win(t_env *env)
{
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "Fract_ol");
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	env->cr = 0.285;
	env->ci = 0.01;
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_hook(env->win, 4, (1L << 2), mouse_hook, env);
	mlx_hook(env->win, 6, (1L << 6), mouse_move, env);
	mlx_hook(env->win, 17, (1L << 17), red_cross, env);
}

void	draw_frct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	if (env->menu == 1)
		ft_julia(env);
	else if (env->menu == 2)
		ft_mandelbrot(env);
	else
		ft_burningship(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}

int		main(void)
{
	t_env	*env;

	if (!ft_init_struct(&env))
		return (-1);
	env->menu = 0;
	env->mlx = mlx_init();
	env->win_b = mlx_new_window(env->mlx, W_X, W_Y, "MENU");
	mlx_hook(env->win_b, 2, 0, key_menu, env);
	mlx_hook(env->win_b, 17, (1L << 17), red_cross, env);
	mlx_loop(env->mlx);
	return (0);
}
