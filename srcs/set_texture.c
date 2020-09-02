/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:49:47 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/09/02 11:02:12 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

int			get_color(t_w3d *w)
{
	int		texwidth;
	int		tex;

	texwidth = w->tex.width / 6;
}

unsigned char	read_text(char *filename, t_w3d *w)
{
	unsigned char	*data;
	FILE			*f;
	unsigned char	info[54];
	unsigned int	size;

	f = fopen(filename, "rb");
	if (f <= 0)
		return (0);
	fread(info, sizeof(unsigned char), 2, f);
	fread(info + 2, sizeof(unsigned char), 52, f);
	w->tex.width = *(int*)&info[18];
	w->tex.height = *(int*)&info[22];
	size = 3 * w->tex.width * w->tex.height;
	data = (unsigned char *)ft_memalloc(size);
	fread(data, 1, size, f);
	fclose(f);
	return (data);
}

void			load_textures(t_w3d *w)
{
	w->tex.textures = read_text("../resources/sheet.bmp", &w->tex);
}