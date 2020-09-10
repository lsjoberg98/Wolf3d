/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:43 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/09/09 11:56:36 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> //remove this when done
# include <fcntl.h> // added for fd args
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include "mouse.h"

# define WIN_WIDTH		(1024)
# define WIN_HEIGHT		(768)
# define TEX_WIDTH		(64)
# define TEX_HEIGHT		(64)

# define A_ALIASING		(0.0050)
# define SPD_WALK		(1.0000)
# define SPD_SPRINT		(2.0000)
# define SPD_MOVE		(0.2)
# define SPD_STRAFE		(0.0750)

# define FT_ABS(x)			(((x) < 0) ? -(x) : (x))

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

typedef struct	s_key
{
	int		debug;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}				t_key;

typedef struct	s_img
{
	char		*data;
	int		size;
	int		endian;
	char	*pixel_img;
	int		pxc;
	int		x;
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

typedef struct	s_text
{
	long	width;
	long	height;
}				t_text;

typedef struct	s_3d
{
	float	x;
	float	y;
	float	z;
}				t_3d;

typedef struct	s_side
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
	double	deltadistX;
	double	deltadistY;
	double	perpwalldist;
	unsigned char	*textures;
}				t_side;

typedef struct s_w3d
{
	t_mlx	mlx;
	t_img	img;
	t_cam	cam;
	t_grid	grid;
	t_key	key;
	t_text	tex;
	t_side	side;
	t_3d	d3;
}				t_w3d;

void		draw_vert(t_w3d *w, int x, int y, int height);
unsigned char	*get_color(t_w3d *w, float height, int start);
void		calc_perp(t_w3d *w, int i);
void		calc_dist_init(t_w3d *w, int i);
int			ft_count_words(const char *str, char c);
void		read_map(char *file_name, t_w3d *w);
void		set_map(t_w3d *w);
float		raycast(t_w3d *w);
void		set_collision(t_w3d *w);
void		set_movement(t_w3d *w);
void		set_hooks(t_w3d *w);
void		set_debug(t_w3d *w);
void		draw_point(t_w3d *w, float height, int start);
void		load_textures(t_w3d *w);

#endif
