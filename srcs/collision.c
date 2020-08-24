/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:59:23 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/24 17:04:30 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	w3d_set_collision(t_w3d *w)
{
	int		x;
	int		y;

	x = (int)(w->cam.moveX);
	y = (int)(w->cam.moveY);
	if ((w->cam.moveX > 0 && w->cam.moveX < 25) \
		&& (w->cam.moveY > 0 && w->cam.moveY < 25))
	{
		w->cam.posX = w->cam.moveX;
		w->cam.posY = w->cam.moveY;
	}
}