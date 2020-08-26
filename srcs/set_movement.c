/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:00:55 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/26 16:13:53 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	move_up(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.moveX = w->cam.posX \
					+ (speed * cos((w->cam.angle / 180.00) * M_PI));
	w->cam.moveY = w->cam.posY \
					+ (speed * sin((w->cam.angle / 180.00) * M_PI));
}

static void	move_down(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.moveX = w->cam.posX \
					- (speed * cos((w->cam.angle / 180.00) * M_PI));
	w->cam.moveY = w->cam.posY \
					- (speed * sin((w->cam.angle / 180) * M_PI));
}

static void	move_left(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.moveY = w->cam.posY \
					+ (speed * cos((w->cam.angle / 180.00) * M_PI));
	w->cam.moveX = w->cam.posX \
					- (speed * sin((w->cam.angle / 180.00) * M_PI));
}

static void	move_right(t_w3d *w, float speed)
{
	speed *= SPD_MOVE;
	w->cam.moveX = w->cam.posX \
					+ (speed * sin((w->cam.angle / 180.00) * M_PI));
	w->cam.moveY = w->cam.posY \
					- (speed * cos((w->cam.angle / 180.00) * M_PI));
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
		w->cam.angle += 1.50;
	if (w->key.rotate_right == 1)
		w->cam.angle -= 1.50;
}
