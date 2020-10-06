/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:20:03 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/06 21:28:44 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_point(t_w3d *w, t_3d p, float height, int start)
{
	int				i;
	unsigned char	*color;
	float			darken;

	i = (p.x * 4) + (p.y * w->img.size);
	if (p.z < 255)
	{
		color = get_color(w, p, height, start);
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

static unsigned char	*get_color(t_w3d *w, t_3d p, float height, int start)
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
}