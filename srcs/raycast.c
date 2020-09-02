/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:38:09 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/09/01 16:04:02 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	color_grid(int grid, int *color, float hitpointx, float hitpointy)
{	
	if (grid >= 1 && grid <= 9 )
	{
		if (hitpointx < 1 && hitpointy > 1 && hitpointy < 10)
			*color = 0x00FF00; //GREEN
		if (hitpointx > 4 && hitpointy > 1 && hitpointy < 10)
			*color = 0xFFFF33; // YELLOW
		if (hitpointx > 1 && hitpointx < 4 && hitpointy < 1)
			*color = 0xFF33FF; // PURPLE
		if (hitpointy > 10)
			*color = 0x33FFFF; // TURQOISE
	}
}

float		raycast(t_w3d *w, int *color)
{
	float	hitpointx;
	float	hitpointy;
	float	raydir;
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
	hitpointx = w->cam.posX + (w->grid.x - w->cam.posX) * raycast;
	hitpointy = w->cam.posY + (w->grid.y - w->cam.posY) * raycast;
	raydir = w->grid.x - w->cam.posX;
	color_grid(w->grid.matrix[x][y], color, hitpointx, hitpointy);
	//printf("RaydirX:%f\n", raydir);
	return (raycast);
}