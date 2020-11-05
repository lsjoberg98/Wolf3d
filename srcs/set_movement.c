/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:56 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/11/05 16:48:06 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf3d.h"

static void	move_down(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.posX -= speed * w->ray.dirx;
	w->cam.posY -= speed * w->ray.diry;

}

static void	move_up(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.posX += speed * w->ray.dirx;
	w->cam.posY += speed * w->ray.diry;

}

static void	move_right(t_w3d *w, float speed)
{
	speed *= SPD_STRAFE;
	w->cam.posX += speed * w->ray.planex;
	w->cam.posY += speed * w->ray.planey;
}

static void	move_left(t_w3d *w, float speed)
{
	speed *= SPD_STRAFE;
	w->cam.posX -= speed * w->ray.planex;
	w->cam.posY -= speed * w->ray.planey;

}

void		rotate_left(t_w3d *w)
{
	double	rspeed;

	rspeed = 0.06;
	w->ray.diroldx = w->ray.dirx;
	w->ray.dirx = w->ray.dirx * cos(rspeed) - w->ray.diry * sin(rspeed);
	w->ray.diry = w->ray.diroldx * sin(rspeed) + w->ray.diry * cos(rspeed);
	w->ray.planeoldx = w->ray.planex;
	w->ray.planex = w->ray.planex * cos(rspeed) - w->ray.planey * sin(rspeed);
	w->ray.planey = w->ray.planeoldx * sin(rspeed) + w->ray.planey * cos(rspeed);
}

void		rotate_right(t_w3d *w)
{
	double	rspeed;

	rspeed = 0.06;
	w->ray.diroldx = w->ray.dirx;
	w->ray.dirx = w->ray.dirx * cos(-rspeed) - w->ray.diry * sin(-rspeed);
	w->ray.diry = w->ray.diroldx * sin(-rspeed) + w->ray.diry * cos(-rspeed);
	w->ray.planeoldx = w->ray.planex;
	w->ray.planex = w->ray.planex * cos(-rspeed) - w->ray.planey * sin(-rspeed);
	w->ray.planey = w->ray.planeoldx * sin(-rspeed) + w->ray.planey * cos(-rspeed);
}

void		set_movement(t_w3d *w)
{
	float	speed;

	speed = 1.00;
	if (w->key.move_up == 1)
		move_up(w, speed);
	if (w->key.move_down == 1)
		move_down(w, speed);
	 if (w->key.move_left == 1)
		move_left(w, speed);
	if (w->key.move_right)
		move_right(w, speed);
	if (w->key.rotate_left == 1)
		rotate_left(w);
	if (w->key.rotate_right == 1)
		rotate_right(w);
	set_collision(w);
	mlx_destroy_image(w->mlx.init, w->mlx.img);
	w->mlx.img = mlx_new_image(w->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	draw_background(w);
	draw_map(w);
	mlx_put_image_to_window(w->mlx.init, w->mlx.win, w->mlx.img, 0, 0);
}