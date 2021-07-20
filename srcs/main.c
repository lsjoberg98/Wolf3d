/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:06:37 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/07/20 18:40:47 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	main(int ac, char **av)
{
	t_w3d	*w;

	if (ac != 2)
		ft_error("Invalid arguments", -1);
	(w = (t_w3d *)malloc(sizeof(t_w3d)));
	if (!w)
		ft_error("Memory Allocation failed", 1);
	w->check = validate_map(av[1]);
	if (w->check == 0)
		ft_error("invalid map, try maps/map1", -1);
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
