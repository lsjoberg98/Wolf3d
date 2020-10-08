/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:49:47 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/08 23:26:38 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		import_textures(t_w3d *w)
{
	int		height;
	int		width;
	
	w->tex.wt = mlx_xpm_file_to_image(w->mlx.init, "./textures/wall.xpm", \
		&width, &height);
	w->tex.fl = mlx_xpm_file_to_image(w->mlx.init, "./textures/stone.xpm", \
		&width, &height);
	w->tex.cl = mlx_xpm_file_to_image(w->mlx.init, "./textures/ceiling.xpm", \
		&width, &height);
}
