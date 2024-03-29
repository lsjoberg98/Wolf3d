/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:12:56 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/07/20 18:08:48 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	move_down(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.pos_x -= speed * w->ray.dirx;
	w->cam.pos_y -= speed * w->ray.diry;
}

static void	move_up(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.pos_x += speed * w->ray.dirx;
	w->cam.pos_y += speed * w->ray.diry;
}

static void	move_right(t_w3d *w, float speed)
{
	speed *= SPD_STRAFE;
	w->cam.pos_x += speed * w->ray.planex;
	w->cam.pos_y += speed * w->ray.planey;
}

static void	move_left(t_w3d *w, float speed)
{
	speed *= SPD_STRAFE;
	w->cam.pos_x -= speed * w->ray.planex;
	w->cam.pos_y -= speed * w->ray.planey;
}

void	set_movement(t_w3d *w)
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
