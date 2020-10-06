/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:38:09 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/06 19:51:39 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	color_grid(t_w3d *w, int *color/*int grid, int *color, float hitpointx, float hitpointy*/)
{
	if (w->side.wallhit == 1)
	{
		if (w->side.side == 1)
			*color = 0x00FF00; //GREEN
		if (w->side.side == 0)
			*color = 0x33FFFF; // TURQOISE
	}
	/*if (grid >= 1 && grid <= 9 )
	{
		if (hitpointx < 1 && hitpointy > 1 && hitpointy < 10)
			*color = 0x00FF00; //GREEN
		if (hitpointx > 4 && hitpointy > 1 && hitpointy < 10)
			*color = 0xFFFF33; // YELLOW
		if (hitpointx > 1 && hitpointx < 4 && hitpointy < 1)
			*color = 0xFF33FF; // PURPLE
		if (hitpointy > 10)
			*color = 0x33FFFF; // TURQOISE
	}*/
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
	color_grid(w, color/*w->grid.matrix[x][y], color, hitpointx, hitpointy*/);
	//printf("RaydirX:%f\n", raydir);
	return (raycast);
}

void	calc_direction(t_w3d *w)
{
	w->side.deltadistX = sqrt(1 + (w->side.lookdiry * w->side.lookdiry) /
		(w->side.lookdirx * w->side.lookdirx));
	w->side.deltadistY = sqrt(1 + (w->side.lookdirx * w->side.lookdirx) /
		(w->side.lookdiry * w->side.lookdiry));
	if (w->side.lookdirx < 0)
	{
		w->side.stepx = -1;
		w->side.sidedistx = (w->side.lookposx - w->side.mapx) * w->side.deltadistX;
	}
	else
	{
		w->side.stepx = 1;
		w->side.sidedistx = (w->side.mapx + 1.0 - w->side.lookposx) * w->side.deltadistX;
	}

	if (w->side.lookdiry < 0)
	{
		w->side.stepy = -1;
		w->side.sidedisty = (w->side.lookposy - w->side.mapy) * w->side.deltadistY;
	}
	else
	{
		w->side.stepy = 1;
		w->side.sidedisty = (w->side.mapy + 1.0 - w->side.lookposy) * w->side.deltadistY;
	}
}

void	calc_side(t_w3d *w)
{
	w->side.wallhit = 0;
	while (w->side.wallhit == 0)
	{
		if (w->side.sidedistx < w->side.sidedisty)
		{
			w->side.sidedistx += w->side.deltadistX;
			w->side.mapx += w->side.stepx;
			w->side.side = 0;
		}
		else
		{
			w->side.sidedisty += w->side.deltadistY;
			w->side.mapy += w->side.stepy;
			w->side.side = 1;
		}
		if (w->grid.matrix[w->side.mapx][w->side.mapy] > 0)
			w->side.wallhit = 1;
	}
}

void	calc_dist_init(t_w3d *w, int i)
{
	w->side.camera = 2 * i / (double)WIN_WIDTH - 1;
	w->side.lookposx = w->cam.posX;
	w->side.lookposy = w->cam.posY;
	w->side.lookdirx = w->side.dirx + w->side.planex * w->side.camera;
	w->side.lookdiry = w->side.diry + w->side.planey * w->side.camera;
	w->side.mapx = (int)w->side.lookposx;
	w->side.mapy = (int)w->side.lookposy;
	calc_direction(w);
	calc_side(w);
	calc_dist(w);
}

void	calc_dist(t_w3d *w)
{	
	if (w->side.side == 0)
		w->side.perpwalldist = (w->side.mapx - w->side.lookposx +
			(1 - w->side.stepx) / 2) / w->side.lookdirx;
	else
		w->side.perpwalldist = (w->side.mapy - w->side.lookposy +
			(1 - w->side.stepy) / 2) / w->side.lookdiry;
}

void	draw_vert(t_w3d *w, int x, int start, int height)
{
	int		i;
	t_3d	point;

	i = -1;
	point.x = x;
	while (++i < WIN_HEIGHT)
	{
		point.y = i;
		if (i < start)
			point.z = 256;
		else if (i < start + height)
			point.z = w->grid.matrix[w->side.mapx][w->side.mapy];
		else
			point.z = 255;
		draw_point(w, point, height, start);
	}
}