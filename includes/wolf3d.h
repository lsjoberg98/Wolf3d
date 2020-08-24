/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:43 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/24 17:05:14 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "mouse.h"

# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)
# define TEX_WIDTH		(64)
# define TEX_HEIGHT		(64)

extern int		g_map[25][25];

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_cam
{
	float	posX;
	float	posY;
	float	moveX;
	float	moveY;
	float	angle;
}				t_cam;


typedef struct	s_img
{
	int	*data;
	int		size;
	int		endian;
	int		pxc;
}				t_img;

typedef	struct	s_grid
{
	float	x;
	float	y;
	float	angle;
}				t_grid;


typedef struct s_w3d
{
	t_mlx	mlx;
	t_img	img;
	t_cam	cam;
	t_grid	grid;
}				t_w3d;

int			main(void);
void		set_map(t_w3d *w);
float		raycast(t_w3d *w, int *color);
void		w3d_set_collision(t_w3d *w);

#endif