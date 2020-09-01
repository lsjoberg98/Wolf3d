/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:59:23 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/31 15:16:02 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	set_collision(t_w3d *w)
{
	int		x;
	int		y;

	x = (int)(w->cam.moveX);
	y = (int)(w->cam.moveY);
	/*if ((w->cam.moveX > 0 && w->cam.moveX < w->grid.height - 1) \
		&& (w->cam.moveY > 0 && w->cam.moveY < w->grid.width - 1))
	{
		w->cam.posX = w->cam.moveX;
		w->cam.posY = w->cam.moveY;
	}*/
	if ((w->grid.matrix[x][y]) == 0)
	{
		w->cam.posX = w->cam.moveX;
		w->cam.posY = w->cam.moveY;
	}
}