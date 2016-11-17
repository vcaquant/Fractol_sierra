/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:51:26 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 17:51:32 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W_X		1200
# define W_Y		700

# define BLACK		0x000000
# define WHI		0xFFFFFF
# define AZUR		0x74D0F1
# define AZUR_F		0x1E7FCB
# define ABSINTHE	0x7FDD4C
# define RED		0x00FF0000
# define BRO		0x00996600
# define G_P		0x0099FF00
# define G_F		0x0000CC00
# define Y_P		0x00CCCC66

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include "../minilibx_macos sierra/mlx.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

typedef struct	s_img
{
	void		*ptr_img;
	char		*bits_img;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void 	*win_b;
	void	*win;
	void	*s_win;

	int		menu;

	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	img_x;
	double	img_y;

	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	int		zoom;
	int		it_max;

	t_img	*img;
	double	r;
	double	g;
	double	b;
}				t_env;

int				ft_init_struct(t_env **env);

void			too_much_help(t_env *env);
int				aff_key(int keycode, t_env *env);
int				key_menu(int keycode, t_env *env);
void			prp_win(t_env *env);

int				aff_help_exit(int keycode, t_env *env);
void			write_command(t_env *env);
void			write_title1(t_env *env);
void			write_title2(t_env *env);
void			aff_help(t_env *env);

void 			Mandelbrot(t_env *env);
void 			Julia(t_env *env);
void 			draw_frct(t_env *env, int key);

#endif
