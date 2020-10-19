/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:49:47 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/19 13:43:07 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		import_textures(t_w3d *w)
{
	int		height;
	int		width;
	
	w->wall[0] = mlx_xpm_file_to_image(w->mlx.init, "./textures/wall.xpm", \
		&width, &height);
	w->wall[1] = mlx_xpm_file_to_image(w->mlx.init, "./textures/stone.xpm", \
		&width, &height);
	w->wall[2] = mlx_xpm_file_to_image(w->mlx.init, "./textures/ceiling.xpm", \
		&width, &height);
}
