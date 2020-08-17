/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:45:57 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/17 16:18:18 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			main(void)
{
	t_w3d	*w3d;
	
	if (!(w3d = (t_w3d *)malloc(sizeof(t_w3d))))
		ft_error("Memory Allocation failed", 1);
	w3d->mlx.init = mlx_init();
	w3d->mlx.win = mlx_new_window(w3d->mlx.init, WIN_WIDTH, \
		WIN_HEIGHT, "Wolfenstein3D");
	w3d->mlx.img = mlx_new_image(w3d->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	w3d->img.data = mlx_get_data_addr(w3d->mlx.img, \
		&w3d->img.pxc, &w3d->img.size, &w3d->img.endian);
	mlx_loop(w3d->mlx.init);
	return (0);
}