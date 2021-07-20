/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:37:33 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/07/20 18:51:54 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_background(t_w3d *w)
{
	int	i;

	i = 0;
	while (i < (w->img.sl * WIN_HEIGHT / 2))
	{
		w->img.data[i / 4] = 0xade6e6;
		i++;
	}
	while (i < (w->img.sl * WIN_HEIGHT))
	{
		w->img.data[i / 4] = 0x696969;
		i++;
	}
}

void	set_collision(t_w3d *w)
{
	int	x;
	int	y;

	x = (int)(w->cam.pos_x);
	y = (int)(w->cam.pos_y);
	if (w->grid.matrix[x][y] == 0)
	{
		w->cam.move_x = w->cam.pos_x;
		w->cam.move_y = w->cam.pos_y;
	}
	if (w->grid.matrix[x][y] != 0)
	{
		w->cam.pos_x = w->cam.move_x;
		w->cam.pos_y = w->cam.move_y;
	}
}

void	init_wolf(t_w3d *w)
{
	w->cam.pos_x = 3.01;
	w->cam.pos_y = 2.01;
	w->ray.dirx = -1;
	w->ray.diry = 0;
	w->ray.planex = 0;
	w->ray.planey = 0.66;
	w->cam.angle = 110.00;
	w->cam.move_x = 0.00;
	w->cam.move_y = 0.00;
	w->key.texture = 1;
	w->ray.rspeed = 0.06;
	w->grid.row = 1;
	load_textures(w);
	render(w);
}

int	validate_map(char *str)
{
	if (ft_strcmp("maps/map2", str) == 0)
		return (1);
	else if (ft_strcmp("maps/map1", str) == 0)
		return (1);
	else
		return (0);
}

void	calc_wall(t_w3d *w, int tmp)
{
	while (++tmp <= w->ray.end)
	{
		if (w->img.x < WIN_WIDTH && tmp < WIN_HEIGHT)
		{
			w->ray.texty = abs((((tmp * 256 - WIN_HEIGHT * 128
								+ w->ray.wallheight * 128) * 64)
						/ w->ray.wallheight) / 256);
			w->img.data[WIN_WIDTH * tmp + w->img.x]
				= w->text[w->ray.n].data[w->ray.texty
				% 16 * w->text[w->ray.n].sl
				+ w->ray.textx % 64 * w->text[w->ray.n].bpp / 8];
		}
	}
}
