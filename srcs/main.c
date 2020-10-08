/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:45:57 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/09 00:40:19 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	t_w3d		*init_values(t_w3d *w)
{
	w->cam.posX = 3.0;
	w->cam.posY = 3.0;
	w->cam.angle = 110.00;
	w->cam.moveX = 0.00;
	w->cam.moveY = 0.00;
	import_textures(w);
	return (w);
}

// https://github.com/Denis2222/wolf3d
int		main(int ac, char **argv)
{
	t_w3d	*w;

	if (ac != 2)
	{
		ft_putendl("Invalid arguments do /maps/mapx");
		exit(-1);
	}
	if (!(w = (t_w3d *)malloc(sizeof(t_w3d))))
		ft_error("Memory Allocation failed", 1);
	read_map(argv[1], w);
	w->mlx.init = mlx_init();
	w->mlx.win = mlx_new_window(w->mlx.init, WIN_WIDTH, \
		WIN_HEIGHT, "Wolfenstein3D");
	w->mlx.img = mlx_new_image(w->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	w->img.data = (int *)mlx_get_data_addr(w->mlx.img, \
		&w->img.pxc, &w->img.size, &w->img.endian);
	w = init_values(w);
	set_hooks(w);
	set_map(w);
	mlx_loop(w->mlx.init);
	return (0);
}
