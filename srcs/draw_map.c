/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:41:58 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/05/26 18:01:38 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	calc_direction(t_w3d *w)
{
	w->ray.dx = sqrt(1 + (w->ray.lookdiry * w->ray.lookdiry) /
		(w->ray.lookdirx * w->ray.lookdirx));
	w->ray.dy = sqrt(1 + (w->ray.lookdirx * w->ray.lookdirx) /
		(w->ray.lookdiry * w->ray.lookdiry));
	if (w->ray.lookdirx < 0)
	{
		w->ray.stepx = -1;
		w->ray.sidedistx = (w->ray.lookposx - w->ray.mapx) * w->ray.dx;
	}
	else
	{
		w->ray.stepx = 1;
		w->ray.sidedistx = (w->ray.mapx + 1.0 - w->ray.lookposx) * w->ray.dx;
	}
	if (w->ray.lookdiry < 0)
	{
		w->ray.stepy = -1;
		w->ray.sidedisty = (w->ray.lookposy - w->ray.mapy) * w->ray.dy;
	}
	else
	{
		w->ray.stepy = 1;
		w->ray.sidedisty = (w->ray.mapy + 1.0 - w->ray.lookposy) * w->ray.dy;
	}
}

void	calc_side(t_w3d *w)
{
	w->ray.wallhit = 0;
	while (w->ray.wallhit == 0)
	{
		if (w->ray.sidedistx < w->ray.sidedisty)
		{
			w->ray.sidedistx += w->ray.dx;
			w->ray.mapx += w->ray.stepx;
			w->ray.side = 0;
		}
		else
		{
			w->ray.sidedisty += w->ray.dy;
			w->ray.mapy += w->ray.stepy;
			w->ray.side = 1;
		}
		if (w->grid.matrix[w->ray.mapx][w->ray.mapy] > 0)
			w->ray.wallhit = 1;
	}
}

void	draw_init(t_w3d *w)
{
	w->ray.camera = 2 * w->img.x / (double)WIN_WIDTH - 1;
	w->ray.lookposx = w->cam.pos_x;
	w->ray.lookposy = w->cam.pos_y;
	w->ray.lookdirx = w->ray.dirx + w->ray.planex * w->ray.camera;
	w->ray.lookdiry = w->ray.diry + w->ray.planey * w->ray.camera;
	w->ray.mapx = (int)w->ray.lookposx;
	w->ray.mapy = (int)w->ray.lookposy;
	calc_direction(w);
	calc_side(w);
	if (w->ray.side == 0)
		w->ray.walldist = (w->ray.mapx - w->ray.lookposx +
			(1 - w->ray.stepx) / 2) / w->ray.lookdirx;
	else
		w->ray.walldist = (w->ray.mapy - w->ray.lookposy +
			(1 - w->ray.stepy) / 2) / w->ray.lookdiry;
}

void	*set_map(void *tab)
{
	t_w3d	*w;

	w = (t_w3d*)tab;
	while (w->img.x < w->img.xmax)
	{
		draw_init(w);
		w->ray.wallheight = abs((int)(WIN_HEIGHT / w->ray.walldist));
		w->ray.start = -w->ray.wallheight / 2 + WIN_HEIGHT / 2;
		if (w->ray.start < 0)
			w->ray.start = 0;
		w->ray.end = w->ray.wallheight / 2 + WIN_HEIGHT / 2;
		if (w->ray.end >= WIN_HEIGHT)
			w->ray.end = WIN_HEIGHT - 1;
		draw_walls(w);
		++w->img.x;
	}
	return (0);
}

void	draw_map(t_w3d *w)
{
	pthread_t	tab[THREADS];
	t_w3d		t[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void*)&t[i], (void*)w, sizeof(t_w3d));
		t[i].img.x = i * (WIN_WIDTH / THREADS);
		t[i].img.xmax = (i + 1) * (WIN_WIDTH / THREADS);
		pthread_create(&tab[i], NULL, set_map, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(tab[i], NULL);
}
