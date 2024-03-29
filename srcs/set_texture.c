/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:17:03 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/07/20 19:11:38 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_textures(t_w3d *w)
{
	int	height;
	int	width;

	w->text[0].img = mlx_xpm_file_to_image(w->mlx.init, "tex/tnt_side.xpm",
			&width, &height);
	w->text[0].data = (int *)(mlx_get_data_addr(w->text[0].img,
				&w->text[0].bpp, &w->text[0].sl, &w->text[0].endian));
	w->text[1].img = mlx_xpm_file_to_image(w->mlx.init, "tex/gold_ore.xpm",
			&width, &height);
	w->text[1].data = (int *)(mlx_get_data_addr(w->text[1].img, &w->text[1].bpp,
				&w->text[1].sl, &w->text[1].endian));
	w->text[2].img = mlx_xpm_file_to_image(w->mlx.init, "tex/mossy.xpm",
			&width, &height);
	w->text[2].data = (int *)(mlx_get_data_addr(w->text[2].img, &w->text[2].bpp,
				&w->text[2].sl, &w->text[2].endian));
	w->text[3].img = mlx_xpm_file_to_image(w->mlx.init, "tex/diamond_ore.xpm",
			&width, &height);
	w->text[3].data = (int *)(mlx_get_data_addr(w->text[3].img, &w->text[3].bpp,
				&w->text[3].sl, &w->text[3].endian));
}

static void	wall_texture(t_w3d *w)
{
	if (w->ray.side == 0)
	{
		w->ray.n = 1;
		w->ray.wall = w->ray.lookposy + w->ray.lookdiry * w->ray.walldist;
		if (w->ray.mapx - w->cam.pos_x > 0)
			w->ray.n = 3;
	}
	else
	{
		w->ray.n = 0;
		w->ray.wall = w->ray.lookposx + w->ray.lookdirx * w->ray.walldist;
		if (w->ray.mapy - w->cam.pos_y > 0)
			w->ray.n = 2;
	}
	w->ray.textx = (int)(w->ray.wall * (double)(64));
	if (w->ray.side == 1 && w->ray.lookdiry < 0)
		w->ray.textx = 64 - w->ray.textx - 1;
	if (w->ray.side == 0 && w->ray.lookdirx > 0)
		w->ray.textx = 64 - w->ray.textx - 1;
	w->ray.textx = abs(w->ray.textx);
}

void	draw_walls(t_w3d *w)
{
	int	tmp;

	tmp = w->ray.start - 1;
	if (w->key.texture == 0)
	{
		if (w->ray.side == 1)
			w->ray.color = ORANGE;
		else
			w->ray.color = RED;
		while (++tmp <= w->ray.end)
			w->img.data[WIN_WIDTH * tmp + w->img.x] = w->ray.color;
	}
	else
		wall_texture(w);
	calc_wall(w, tmp);
}

void	rotate_right(t_w3d *w)
{
	double	rspeed;

	rspeed = 0.1;
	w->ray.diroldx = w->ray.dirx;
	w->ray.dirx = w->ray.dirx * cos(-rspeed) - w->ray.diry * sin(-rspeed);
	w->ray.diry = w->ray.diroldx * sin(-rspeed) + w->ray.diry * cos(-rspeed);
	w->ray.planeoldx = w->ray.planex;
	w->ray.planex = w->ray.planex * cos(-rspeed) - w->ray.planey * sin(-rspeed);
	w->ray.planey = w->ray.planeoldx * sin(-rspeed)
		+ w->ray.planey * cos(-rspeed);
}

void	rotate_left(t_w3d *w)
{
	double	rspeed;

	rspeed = 0.1;
	w->ray.diroldx = w->ray.dirx;
	w->ray.dirx = w->ray.dirx * cos(rspeed) - w->ray.diry * sin(rspeed);
	w->ray.diry = w->ray.diroldx * sin(rspeed)
		+ w->ray.diry * cos(rspeed);
	w->ray.planeoldx = w->ray.planex;
	w->ray.planex = w->ray.planex * cos(rspeed) - w->ray.planey * sin(rspeed);
	w->ray.planey = w->ray.planeoldx * sin(rspeed)
		+ w->ray.planey * cos(rspeed);
}
