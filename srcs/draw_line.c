/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:20:03 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/08 23:51:07 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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

void		draw_point(t_w3d *w, t_3d p, float height, int start)
{
	int				i;
	int				*color;
	float			darken;

	i = (p.x * 4) + (p.y * w->img.size);
	if (p.z < 255)
	{
		color = get_color(w, color, height, start);
		darken = MAX(0, MIN(1, height / WIN_HEIGHT - 0.05));
	}
	else
	{
		darken = MAX(0, MIN(1, 1 - (WIN_HEIGHT - p.y) /
			(float)WIN_HEIGHT * 1.3));
		w->img.data[i] = (p.z == 255) ? 0x30 * darken : 0;
		w->img.data[++i] = (p.z == 255) ? 0x30 * darken : 0;
		w->img.data[++i] = (p.z == 255) ? 0x30 * darken : 0;
		return ;
	}
	if (p.x > 0 && p.y > 0 && p.x < WIN_WIDTH && p.y < WIN_HEIGHT)
	{
		w->img.data[i] = (color[0]) * darken;
		w->img.data[++i] = (color[1]) * darken;
		w->img.data[++i] = (color[2]) * darken; 
	}
}

static unsigned char	*get_color(t_w3d *w, int color, float height, int start)
{
	double	wallx;
	int		texwidth;
	int		y;
	int		texx;

	texwidth = TEX_WIDTH;
	if (w->side.side == 0)
		wallx = w->side.lookposy + w->side.perpwalldist * w->side.lookdiry;
	else
		wallx = w->side.lookposx + w->side.perpwalldist * w->side.lookdirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)texwidth);
	if (w->side.side == 0 && w->side.lookdirx > 0)
		texx = texwidth - texx - 1;
	if (w->side.side == 1 && w->side.lookdiry < 0)
		texx = texwidth - texx - 1;
	y = TEX_HEIGHT - ((w->cord.y - start) / height * 64);
	return (color);
}