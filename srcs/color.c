/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:19:05 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/15 15:42:28 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_dot(t_w3d *w, int x, int y, int color)
{
	char	r;
	char	g;
	char	b;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	r = (color / 256 / 256) % 256;
	g = (color / 256) % 256;
	b = color % 256;
	i = (w->img.size * y) + (x * (w->img.pxc / 8));
	w->img.data[i] = b;
	w->img.data[i + 1] = g;
	w->img.data[i + 2] = r;
}

int		get_color(t_w3d *w, int x, int y, int fade)
{
	int color;
	int	c;

	fade /= 8;
	c = (y * w->side.buffer)
}