/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:17:03 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/04/29 18:09:03 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		load_textures(t_w3d *w)
{
	int	height;
	int	width;

	w->text[0].img = XPM(w->mlx.init, "tex/tnt_side.xpm", &width, &height);
	w->text[0].data = (int *)(XPMA(w->text[0].img, &w->text[0].bpp,
		&w->text[0].sl, &w->text[0].endian));
	w->text[1].img = XPM(w->mlx.init, "tex/gold_ore.xpm", &width, &height);
	w->text[1].data = (int *)(XPMA(w->text[1].img, &w->text[1].bpp,
		&w->text[1].sl, &w->text[1].endian));
	w->text[2].img = XPM(w->mlx.init, "tex/mossy.xpm", &width, &height);
	w->text[2].data = (int *)(XPMA(w->text[2].img, &w->text[2].bpp,
		&w->text[2].sl, &w->text[2].endian));
	w->text[3].img = XPM(w->mlx.init, "tex/diamond_ore.xpm", &width, &height);
	w->text[3].data = (int *)(XPMA(w->text[3].img, &w->text[3].bpp,
		&w->text[3].sl, &w->text[3].endian));
}

static void	wall_texture(t_w3d *w, int tmp)
{
	if (w->ray.side == 0)
	{
		w->ray.n = 1;
		w->ray.wall = w->ray.lookposy + w->ray.lookdiry * w->ray.walldist;
		if (w->ray.mapx - w->cam.posX > 0)
			w->ray.n = 3;
	}
	else
	{
		w->ray.n = 0;
		w->ray.wall = w->ray.lookposx + w->ray.lookdirx * w->ray.walldist;
		if (w->ray.mapy - w->cam.posY > 0)
			w->ray.n = 2;
	}
	w->ray.textx = (int)(w->ray.wall * (double)(64));
	if (w->ray.side == 1 && w->ray.lookdiry < 0)
		w->ray.textx = 64 - w->ray.textx - 1;
	if (w->ray.side == 0 && w->ray.lookdirx > 0)
		w->ray.textx = 64 - w->ray.textx - 1;
	w->ray.textx = abs(w->ray.textx);
	while (++tmp <= w->ray.end)
	{
		if (w->img.x < WIN_WIDTH && tmp < WIN_HEIGHT)
		{
			w->ray.texty = abs((((tmp * 256 - WIN_HEIGHT * 128 +
				w->ray.wallheight * 128) * 64) / w->ray.wallheight) / 256);
		w->img.data[WIN_WIDTH * tmp + w->img.x] =
			w->text[w->ray.n].data[w->ray.texty % 16 * w->text[w->ray.n].sl +
				w->ray.textx % 64 * w->text[w->ray.n].bpp / 8];
		}
	}
}

void		draw_walls(t_w3d *w)
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
		wall_texture(w, tmp);
}
