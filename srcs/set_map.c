/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:16:11 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/24 17:12:41 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_pixel(t_w3d *w, int color, int x, float ray)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	y = ((WIN_HEIGHT / 2) * w->img.size) + (x * w->img.pxc / 8);
	while (i < (WIN_HEIGHT / (2 * ray)))
	{
		j = 0;
		while (j < (w->img.pxc / 8))
		{
			w->img.data[(j + y - (i * w->img.size)) / 4] = color;
			w->img.data[(j + y + (i * w->img.size)) / 4] = color;
			j++;
		}
		i++;
	}
}

static void		draw_grids(t_w3d *w)
{
	int		i;
	int		color;
	float	tmp_y;
	float	ray;

	i = 0;
	w->grid.angle = (w->cam.angle / 180.00) * 3.141592;
	while (i < WIN_WIDTH)
	{
		tmp_y = ((WIN_WIDTH / 2) - (float)i) / WIN_WIDTH;
		w->grid.x = cos(w->grid.angle) - tmp_y * sin(w->grid.angle);
		w->grid.y = sin(w->grid.angle) + tmp_y * cos(w->grid.angle);
		w->grid.x += w->cam.posX;
		w->grid.y += w->cam.posY;
		ray = raycast(w, &color);
		put_pixel(w, color, i, ray);
		i++;
	}
}

static void		draw_background(t_w3d *w)
{
	int		i;

	i = 0;
	while (i < (w->img.size * WIN_HEIGHT / 2))
	{
		w->img.data[i / 4] = 0xffffff;
		i++;
	}
	while (i < (w->img.size * WIN_HEIGHT))
	{
		w->img.data[i / 4] =  0xDC143C;
		i++;
	}
}

void		set_map(t_w3d *w)
{
	draw_background(w);
	draw_grids(w);
	mlx_put_image_to_window(w->mlx.init, w->mlx.win, w->mlx.img, 0, 0);
}