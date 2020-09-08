/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:49:47 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/09/08 18:24:08 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	find_sheet(t_w3d *w, int z)
{
	int	ret;

	if (z == 1)
		ret = (0);
	else if (z == 2)
		ret = -220416;
	else if (z == 3)
		ret = -368256;
	else if (z == 4)
		ret = -884352;
	else if (z == 5)
		ret = -1179648;
	else
		ret = 0;
	if (w->side.side)
		ret += 64 * 3;
	return (ret);
}

unsigned char	*get_color(t_w3d *w, float height, int start)
{
	double	wallx;
	int		texwidth;
	int		texx;
	int		y;

	texwidth = w->tex.width / 6;
	if (w->side.side == 0)
		wallx = w->side.lookposy + w->side.perpwalldist * w->side.lookdiry;
	else
		wallx = w->side.lookposx + w->side.perpwalldist * w->side.lookdirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)texwidth);
	if (w->side.side == 0 && w->side.lookdirx > 0)
		texx = texwidth - texx - 1;
	if (w->side.side == 1 && w->side.lookdiry < 0)
		texx = texwidth - texx - 1;
	y = w->tex.height - ((w->d3.y - start) / height * 64);
	return (w->side.textures + ((texx + y * w->tex.width) * 3)
		+ find_sheet(w, w->d3.z));
}

unsigned char	*read_text(char *filename, t_text *tex)
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
	tex->width = *(int*)&info[18];
	tex->height = *(int*)&info[22];
	size = 3 * tex->width * tex->height;
	data = (unsigned char *)ft_memalloc(size);
	fread(data, 1, size, f);
	fclose(f);
	return (data);
}

void			load_textures(t_w3d *w)
{
	w->side.textures = read_text("../resources/sheet.bmp", &w->tex);
}

void			calc_perp(t_w3d *w, int i)
{
	int	lineheight;
	int drawstart;
	
	if (w->side.side == 0)
		w->side.perpwalldist = (w->grid.x - w->side.lookposx +
			(1 - w->side.stepx) / 2) / w->side.lookdirx;
	else
		w->side.perpwalldist = (w->grid.y - w->side.lookposy +
			(1 - w->side.stepy) / 2) / w->side.lookdiry;
	lineheight = (int)(WIN_HEIGHT / w->side.perpwalldist);
	drawstart = -lineheight / 2 + WIN_HEIGHT / 2;
	draw_vert(w, i, drawstart, lineheight);
}

void		draw_vert(t_w3d *w, int x, int y, int height)
{
	int		i;

	i = -1;
	w->d3.x = x;
	while (++i < WIN_HEIGHT)
	{
		w->d3.y = i;
		if (i < y)
			w->d3.z = 256;
		else if (i < y + height)
			w->d3.z = w->grid.matrix[w->side.mapx][w->side.mapy];
		else
			w->d3.z = 255;
		draw_point(w, height, y);
	}
}