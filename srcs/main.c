/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:06:37 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/11/02 15:24:30 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_background(t_w3d *w)
{
	int i;

	i = 0;
	while (i < (w->img.sl * WIN_HEIGHT / 2))
	{
		w->img.data[i / 4] = 0xade6e6;
		i++;
	}
	while (i < (w->img.sl * WIN_HEIGHT))
	{
		w->img.data[i / 4] =  0x696969;
		i++;
	}
}

void	set_collision(t_w3d *w)
{
	int x;
	int y;

	x = (int)(w->cam.posX);
	y = (int)(w->cam.posY);
	if (w->grid.matrix[x][y] == 0)
	{
		w->cam.moveX = w->cam.posX;
		w->cam.moveY = w->cam.posY;
	}
	if (w->grid.matrix[x][y] != 0)
	{
		w->cam.posX = w->cam.moveX;
		w->cam.posY = w->cam.moveY;
	}
}

static void	init_wolf(t_w3d *w)
{
	w->cam.posX = 3.0;
	w->cam.posY = 2.0;
	w->ray.dirx = -1;
	w->ray.diry = 0;
	w->ray.planex = 0;
	w->ray.planey = 0.66;
	w->cam.angle = 110.00;
	w->cam.moveX = 0.00;
	w->cam.moveY = 0.00;
	w->key.texture = 1;
	w->ray.rspeed = 0.06;
	load_textures(w);
	render(w);
}

int			main(int ac, char **av)
{
	t_w3d	*w;

	if (ac != 2)
		ft_error("Invalid arguments", -1);
	if (!(w = (t_w3d *)malloc(sizeof(t_w3d))))
		ft_error("Memory Allocation failed", 1);
	read_map(av[1], w);
	w->mlx.init = mlx_init();
	w->mlx.win = mlx_new_window(w->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
		"Wolf3D");
	w->mlx.img = mlx_new_image(w->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	w->img.data = (int *)mlx_get_data_addr(w->mlx.img, \
		&w->img.bpp, &w->img.sl, &w->img.endian);
	draw_background(w);
	init_wolf(w);
	return (0);
}