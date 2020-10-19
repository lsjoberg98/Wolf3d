/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:20:03 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/19 17:51:05 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// void	draw_vert(t_w3d *w, int x, int start, int height)
// {
// 	int		i;
// 	t_3d	point;

// 	i = -1;
// 	point.x = x;
// 	while (++i < WIN_HEIGHT)
// 	{
// 		point.y = i;
// 		if (i < start)
// 			point.z = 256;
// 		else if (i < start + height)
// 			point.z = w->grid.matrix[w->side.mapx][w->side.mapy];
// 		else
// 			point.z = 255;
// 		draw_point(w, point, height, start);
// 	}
// }

// void		draw_point(t_w3d *w, t_3d p, float height, int start)
// {
// 	int				i;
// 	int				*color;
// 	float			darken;

// 	i = (p.x * 4) + (p.y * w->img.size);
// 	if (p.z < 255)
// 	{
// 		color = get_color(w, color, height, start);
// 		darken = MAX(0, MIN(1, height / WIN_HEIGHT - 0.05));
// 	}
// 	else
// 	{
// 		darken = MAX(0, MIN(1, 1 - (WIN_HEIGHT - p.y) /
// 			(float)WIN_HEIGHT * 1.3));
// 		w->img.data[i] = (p.z == 255) ? 0x30 * darken : 0;
// 		w->img.data[++i] = (p.z == 255) ? 0x30 * darken : 0;
// 		w->img.data[++i] = (p.z == 255) ? 0x30 * darken : 0;
// 		return ;
// 	}
// 	if (p.x > 0 && p.y > 0 && p.x < WIN_WIDTH && p.y < WIN_HEIGHT)
// 	{
// 		w->img.data[i] = (color[0]) * darken;
// 		w->img.data[++i] = (color[1]) * darken;
// 		w->img.data[++i] = (color[2]) * darken; 
// 	}
// }

// static unsigned char	*get_color(t_w3d *w, int color, float height, int start)
// {
// 	double	wallx;
// 	int		texwidth;
// 	int		y;
// 	int		texx;

// 	texwidth = TEX_WIDTH;
// 	if (w->side.side == 0)
// 		wallx = w->side.lookposy + w->side.perpwalldist * w->side.lookdiry;
// 	else
// 		wallx = w->side.lookposx + w->side.perpwalldist * w->side.lookdirx;
// 	wallx -= floor(wallx);
// 	texx = (int)(wallx * (double)texwidth);
// 	if (w->side.side == 0 && w->side.lookdirx > 0)
// 		texx = texwidth - texx - 1;
// 	if (w->side.side == 1 && w->side.lookdiry < 0)
// 		texx = texwidth - texx - 1;
// 	y = TEX_HEIGHT - ((w->cord.y - start) / height * 64);
// 	return (color);
// }

static void	draw_ray_wall(t_w3d *w)
{
	int	d;
	int	wall;

	wall = w->grid.matrix[w->side.mapy][w->side.mapx];
	while (w->ray.y < w->ray.drawend)
	{
		d = w->ray.y * 256 - WIN_HEIGHT * 128 + w->ray.height * 128;
		w->ray.texy = ((d * 64) / w->ray.height) / 256;
		draw_dot(w, w->ray.x, w->ray.y, get_color(w->wall[wall + 1],
			w->ray.texx, w->ray.texy, w->side.perpwalldist));
		w->ray.y++;
	}
}

static void	ray_delimiter(t_w3d *w)
{
	w->ray.height = (int)(WIN_HEIGHT / w->side.perpwalldist);
	w->ray.start = -w->ray.height / 2 + WIN_HEIGHT / 2;
	if (w->ray.start < 0)
		w->ray.start = 0;
	w->ray.drawend = w->ray.height / 2 + WIN_HEIGHT / 2;
	if (w->ray.drawend >= WIN_HEIGHT)
		w->ray.drawend = WIN_HEIGHT - 1;
	if (w->side.side == 0)
		w->ray.wallx = w->side.lookposy + w->side.perpwalldist * w->side.lookdiry;
	else
		w->ray.wallx = w->side.lookposx + w->side.perpwalldist * w->side.lookdirx;
	w->ray.wallx -= floor(w->ray.wallx);
	w->ray.texx = (int)(w->ray.wallx * (double)64);
	w->ray.texx = 64 - w->ray.texx - 1;
	w->ray.y = 0;
}

void		draw_floor_size(t_w3d *w)
{
	if (w->side.side == 0 && w->side.lookdirx > 0)
	{
		w->ray.floorxwall = w->side.mapx;
		w->ray.floorywall = w->side.mapy + w->ray.wallx;
	}
	else if (w->side.side == 0 && w->side.lookdirx < 0)
	{
		w->ray.floorxwall = w->side.mapx + 1.0;
		w->ray.floorywall = w->side.mapy + w->ray.wallx;
	}
	else if (w->side.side == 1 && w->side.lookdirx > 0)
	{
		w->ray.floorxwall = w->side.mapx + w->ray.wallx;
		w->ray.floorywall = w->side.mapy;
	}
	else
	{
		w->ray.floorxwall = w->side.mapx + w->ray.wallx;
		w->ray.floorywall = w->side.mapy + 1.0;
	}
	w->ray.distwall = w->side.perpwalldist;
	w->ray.distplayer = 0.0;
}

void		draw_ray_floor(t_w3d *w)
{
	draw_floor_size(w);
	while (w->ray.y < WIN_HEIGHT)
	{
		w->ray.currentdist = WIN_HEIGHT / (2.0 * w->ray.y - WIN_HEIGHT);
		w->ray.weight = (w->ray.currentdist - w->ray.distplayer)
			/ (w->ray.distwall - w->ray.distplayer);
		w->ray.floorx = w->ray.weight * w->ray.floorxwall
			+ (1.0 - w->ray.weight) * w->cam.posX;
		w->ray.floory = w->ray.weight * w->ray.floorywall
			+ (1.0 - w->ray.weight) * w->cam.posY;
		w->ray.floortexx = (int)(w->ray.floorx * 64) % 64;
		w->ray.floortexy = (int)(w->ray.floory * 64) % 64;
		draw_dot(w, w->ray.x, w->ray.y,
			get_color(w->wall[1], w->ray.floortexx, w->ray.floortexy, 0));
		draw_dot(w, w->ray.x, w->ray.y,
			get_color(w->wall[2], w->ray.floortexx, w->ray.floortexy, 0));
		w->ray.y++;
	}
}

void		draw_ray(t_w3d *w, int i)
{
	ray_delimiter(w);
	w->ray.x = i;
	w->side.zbuffer[i] = w->side.perpwalldist;
	draw_ray_wall(w);
	draw_ray_floor(w);
}