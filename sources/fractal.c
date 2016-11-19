/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:33:56 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 15:53:06 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	maptoreal(int x, int img_x, double minr, double maxr)
{
	double	range;

	range = maxr - minr;
	return (x * (range / img_x) + minr);
}

double	maptoimaginary(int y, int img_y, double mini, double maxi)
{
	double	range;

	range = maxi - mini;
	return (y * (range / img_y) + mini);
}
