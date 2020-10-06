/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:49:47 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/10/06 21:10:43 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void		import_textures(t_w3d *w)
{
	w->tex.wt = mlx_xpm_to_image(w->mlx.init, "./textures/wall.xpm", 64, 64);
	w->tex.fl = mlx_xpm_to_image(w->mlx.init, "./textures/stone.xpm", 64, 64);
	w->tex.cl = mlx_xpm_to_image(w->mlx.init, "./textures/ceiling.xpm", 64, 64);
}