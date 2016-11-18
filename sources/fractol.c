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

int		ft_init_struct(t_env **env)
{
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->s_win = NULL;
	if (!((*env)->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	(*env)->zoom = 200;
	(*env)->it_max = 50;
	return (1);
}

void	prp_win(t_env *env)
{
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "Fract_ol");
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, 1200, 700);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	mlx_hook(env->win, 2, 0, aff_key, env);
}

void	draw_frct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, 1200, 700);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	ft_mandelbrot(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}

int		main(void)
{
	t_env	*env;

	if (!ft_init_struct(&env))
		return (-1);
	env->mlx = mlx_init();
	env->win_b = mlx_new_window(env->mlx, W_X, W_Y, "MENU");
	mlx_hook(env->win_b, 2, 0, key_menu, env);
	mlx_loop(env->mlx);
	return (0);
}
