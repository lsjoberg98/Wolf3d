/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:14:16 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/26 15:17:03 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	exit_hook(t_w3d *w)
{
	mlx_destroy_image(w->mlx.init, w->mlx.win);
	exit(0);
}

static int	key_release(int key, t_w3d *w)
{
	if (key == KEY_ANSI_W || key == KEY_UPARROW)
		w->key.move_up = 0;
	else if (key == KEY_ANSI_A || key == KEY_LEFTARROW)
		w->key.move_left = 0;
	else if (key == KEY_ANSI_S || key == KEY_DOWNARROW)
		w->key.move_down = 0;
	else if (key == KEY_ANSI_D || key == KEY_RIGHTARROW)
		w->key.move_right = 0;
	else if (key == KEY_ANSI_Q)
		w->key.rotate_left = 0;
	else if (key == KEY_ANSI_E)
		w->key.rotate_right = 0;
	set_movement(w);
	set_map(w);
	return (0);
}

static int	key_press(int key, t_w3d *w)
{
	if (key == KEY_ESCAPE)
		exit_hook(w);
	else if (key == KEY_ANSI_W || key == KEY_UPARROW)
		w->key.move_up = 1;
	else if (key == KEY_ANSI_A || key == KEY_LEFTARROW)
		w->key.move_left = 1;
	else if (key == KEY_ANSI_S || key == KEY_DOWNARROW)
		w->key.move_down = 1;
	else if (key == KEY_ANSI_D || key == KEY_RIGHTARROW)
		w->key.move_right = 1;
	else if (key == KEY_ANSI_Z)
		w->key.debug = ((w->key.debug == 1) ? 0 : 1);
	else if (key == KEY_ANSI_Q)
		w->key.rotate_left = 1;
	else if (key == KEY_ANSI_E)
		w->key.rotate_right = 1;
	set_movement(w);
	set_map(w);
	return (0);
}

void		set_hooks(t_w3d *w)
{
	mlx_hook(w->mlx.win, 2, 0, key_press, w);
	mlx_hook(w->mlx.win, 3, 0, key_release, w);
	mlx_hook(w->mlx.win, 17, 0, exit_hook, w);
}