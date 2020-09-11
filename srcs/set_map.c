/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:16:11 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/09/11 13:03:04 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		put_pixel(t_w3d *w, int x, int height, int start)
{
	int		i;
	int		j;
	int		y;
	int		*color;

	if (w->d3.z < 255)
		color = get_color(w, height, start);
	i = 0;
	y = ((WIN_HEIGHT / 2) * w->img.size) + (x * w->img.pxc / 8);
	while (i < (WIN_HEIGHT / (2 * w->cam.ray)))
	{
		j = 0;
		while (j < (w->img.pxc / 8))
		{
			w->img.data[(j + y - (i * w->img.size)) / 4] = color[0];
			w->img.data[(j + y + (i * w->img.size)) / 4] = color[1];
			j++;
		}
		i++;
	}
}

// void			draw_point(t_w3d *w, float height, int start)
// {
// 	int				i;
// 	unsigned char	*color;
// 	// float			darken;

// 	i = (w->d3.x * 4) + (w->d3.y * w->img.size);
// 	if (w->d3.z < 255)
// 	{
// 		color = get_color(w, height, start);
// 	}
// 	else
// 	{
// 		w->img.data[i] = (w->d3.z == 255) ? 0x30 : 0;
// 		w->img.data[++i] = (w->d3.z == 255) ? 0x30 : 0;
// 		w->img.data[++i] = (w->d3.z == 255) ? 0x30 : 0;
// 		return ;
// 	}
// 	if (w->d3.x > 0 && w->d3.y > 0 && w->d3.x < WIN_WIDTH && w->d3.y < WIN_HEIGHT)
// 	{
// 		w->img.data[i] = color[0];
// 		w->img.data[++i] = color[0];
// 		w->img.data[++i] = color[0];
// 	}
	
// }

static void		draw_grids(t_w3d *w)
{
	int		i;
	float	tmp_y;
	// float	ray;
	// unsigned char	*color;
	
	i = 0;
	w->grid.angle = (w->cam.angle / 180.00) * M_PI;
	while (i < WIN_WIDTH)
	{
		tmp_y = ((WIN_WIDTH / 2) - (float)i) / WIN_WIDTH;
		w->grid.x = cos(w->grid.angle) - tmp_y * sin(w->grid.angle);
		w->grid.y = sin(w->grid.angle) + tmp_y * cos(w->grid.angle);
		w->grid.x += w->cam.posX;
		w->grid.y += w->cam.posY;
		w->cam.ray = raycast(w);
		calc_dist_init(w, i);
		
		// put_pixel(w, color, i, ray);
		i++;
	}
}

static void		draw_background(t_w3d *w)
{
	int i;

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
	load_textures(w);
	draw_background(w);
	draw_grids(w);
	set_collision(w);
	mlx_put_image_to_window(w->mlx.init, w->mlx.win, w->mlx.img, 0, 0);
	if (w->key.debug == 1)
		set_debug(w);
}
