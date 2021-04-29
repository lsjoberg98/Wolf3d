/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:59:12 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/04/29 18:06:51 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h> // added for fd args

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "mouse.h"

# define WIN_WIDTH		(1200)
# define WIN_HEIGHT		(800)

# define SPD_WALK		(0.5000)
# define SPD_SPRINT		(0.5000)
# define SPD_MOVE		(0.1)
# define SPD_STRAFE		(0.250)

# define RED 16711680
# define ORANGE 16742400

# define THREADS		(8)

# define XPM mlx_xpm_file_to_image
# define XPMA mlx_get_data_addr

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_text
{
	void		*img;
	int			*data;
	int			endian;
	int			sl;
	int			bpp;
}				t_text;

typedef struct	s_key
{
	int		debug;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
	int		texture;
}				t_key;

typedef struct	s_img
{
	int		*data;
	int		sl;
	int		endian;
	int		bpp;
	int		x;
	int		xmax;
}				t_img;

typedef	struct	s_grid
{
	float	x;
	float	y;
	float	angle;
	int		height;
	int		width;
	int		**matrix;
}				t_grid;

typedef struct	s_ray
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camera;
	double	lookposx;
	double	lookposy;
	double	lookdirx;
	double	lookdiry;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		wallhit;
	int		side;
	double	sidedistx;
	double	sidedisty;
	double	dx;
	double	dy;
	double	walldist;
	int		wallheight;
	int		start;
	int		end;
	int		color;
	int		n;
	int			textx;
	int			texty;
	int			texture;
	double	rspeed;
	double	diroldx;
	double	planeoldx;
	double	wall;
}				t_ray;

typedef struct	s_cam
{
	float	posX;
	float	posY;
	float	moveX;
	float	moveY;
	float	angle;
}				t_cam;

typedef struct	s_w3d
{
	t_mlx	mlx;
	t_text	text[4];
	t_img	img;
	t_grid	grid;
	t_key	key;
	t_cam	cam;
	t_ray	ray;
	int		check;
}				t_w3d;

void	*set_map(void *tab);
void	read_map(char *file_name, t_w3d *w);
void	set_movement(t_w3d *w);
void	draw_map(t_w3d *w);
void	render(t_w3d *w);
void	load_textures(t_w3d *w);
void	draw_walls(t_w3d *w);
int		ft_count_words(const char *str, char c);
void	set_collision(t_w3d *w);
void	draw_background(t_w3d *w);
void		rotate_right(t_w3d *w);

#endif