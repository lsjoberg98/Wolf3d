/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:38:09 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/24 16:55:09 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	color_grid(int grid, int *color)
{
	if (grid >= 1 && grid <= 9)
	{
		*color = 0x111111;
	}
}

float		raycast(t_w3d *w, int *color)
{
	int		x;
	int		y;
	float	raycast;

	raycast = 1.00;
	x = w->cam.posX + (raycast * (w->grid.x - w->cam.posX));
	y = w->cam.posY + (raycast * (w->grid.y - w->cam.posY));
	while (g_map[x][y] == 0)
	{
		x = w->cam.posX + (raycast * (w->grid.x - w->cam.posX));
		y = w->cam.posY + (raycast * (w->grid.y - w->cam.posY));
		raycast += 0.0050;
	}
	color_grid(g_map[x][y], color);
	return (raycast);
}