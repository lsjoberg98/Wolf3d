/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:38:09 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/31 12:40:14 by khakala          ###   ########.fr       */
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
	while (w->grid.matrix[x][y] == 0)
	{
		x = w->cam.posX + (raycast * (w->grid.x - w->cam.posX));
		y = w->cam.posY + (raycast * (w->grid.y - w->cam.posY));
		raycast += 0.0050;
	}
	color_grid(w->grid.matrix[x][y], color);
	return (raycast);
}