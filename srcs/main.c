/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:45:57 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/20 14:48:36 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	t_w3d		*init_values(t_w3d *w)
{
	w->cam.posX = 18.0;
	w->cam.posY = 3.0;
	w->cam.angle = 110.00;
	w->cam.moveX = 0.00;
	w->cam.moveY = 0.00;
}

int			main(void)
{
	t_w3d	*w;

	if (!(w = (t_w3d *)malloc(sizeof(t_w3d))))
		ft_error("Memory Allocation failed", 1);
	w->mlx.init = mlx_init();
	w->mlx.win = mlx_new_window(w->mlx.init, WIN_WIDTH, \
		WIN_HEIGHT, "Wolfenstein3D");
	w->mlx.img = mlx_new_image(w->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	w->img.data = mlx_get_data_addr(w->mlx.img, \
		&w->img.pxc, &w->img.size, &w->img.endian);
	mlx_loop(w->mlx.init);
	return (0);
}