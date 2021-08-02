/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:59:12 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/08/02 17:13:45 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"

# define WIN_WIDTH		(1200)
# define WIN_HEIGHT		(800)

# define SPD_MOVE		(0.25)
# define SPD_STRAFE		(0.250)

# define KEY_ANSI_A			 		(0)
# define KEY_ANSI_S			 		(1)
# define KEY_ANSI_D			 		(2)
# define KEY_ANSI_W			 		(13)
# define KEY_ANSI_E			 		(14)
# define KEY_ANSI_Q			 		(12)

# define KEY_LEFTARROW		  		(123)
# define KEY_RIGHTARROW		 		(124)
# define KEY_DOWNARROW		  		(125)
# define KEY_UPARROW				(126)

# define KEY_ESCAPE			 		(53)

# define RED 16711680
# define ORANGE 16742400

# define THREADS		(8)

typedef struct s_mlx
{
	void		*init;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct s_text
{
	void		*img;
	int			*data;
	int			endian;
	int			sl;
	int			bpp;
}				t_text;

typedef struct s_key
{
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
	int			texture;
}				t_key;

typedef struct s_img
{
	int			*data;
	int			sl;
	int			endian;
	int			bpp;
	int			x;
	int			xmax;
}				t_img;

typedef struct s_grid
{
	float		x;
	float		y;
	float		angle;
	int			height;
	int			width;
	int			**matrix;
	int			row;
}				t_grid;

typedef struct s_ray
{
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camera;
	double		lookposx;
	double		lookposy;
	double		lookdirx;
	double		lookdiry;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			wallhit;
	int			side;
	double		sidedistx;
	double		sidedisty;
	double		dx;
	double		dy;
	double		walldist;
	int			wallheight;
	int			start;
	int			end;
	int			color;
	int			n;
	int			textx;
	int			texty;
	int			texture;
	double		rspeed;
	double		diroldx;
	double		planeoldx;
	double		wall;
}				t_ray;

typedef struct s_cam
{
	float		pos_x;
	float		pos_y;
	float		move_x;
	float		move_y;
	float		angle;
}				t_cam;

typedef struct s_w3d
{
	t_mlx		mlx;
	t_text		text[4];
	t_img		img;
	t_grid		grid;
	t_key		key;
	t_cam		cam;
	t_ray		ray;
	int			check;
}				t_w3d;

void			draw_background(t_w3d *w);
void			*set_map(void *tab);
void			read_map(char *file_name, t_w3d *w);
void			set_movement(t_w3d *w);
void			draw_map(t_w3d *w);
void			render(t_w3d *w);
void			load_textures(t_w3d *w);
void			draw_walls(t_w3d *w);
int				ft_count_words(const char *str, char c);
void			set_collision(t_w3d *w);
void			draw_background(t_w3d *w);
void			rotate_right(t_w3d *w);
void			rotate_left(t_w3d *w);
void			check_outer_bounder(int *z_line, int i, t_w3d *w);
void			calc_wall(t_w3d *w, int tmp);
int				validate_map(char *str);
void			init_wolf(t_w3d *w);

#endif
