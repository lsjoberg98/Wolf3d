/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 22:12:18 by lsjoberg          #+#    #+#             */
/*   Updated: 2021/07/20 18:19:33 by lsjoberg         ###   ########.fr       */
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
	draw_map(w);
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
	else if (key == KEY_ANSI_Q)
		w->key.rotate_left = 1;
	else if (key == KEY_ANSI_E)
		w->key.rotate_right = 1;
	set_movement(w);
	draw_map(w);
	return (0);
}

void	render(t_w3d *w)
{
	mlx_hook(w->mlx.win, 17, 0, exit_hook, w);
	mlx_hook(w->mlx.win, 2, 0, key_press, w);
	mlx_hook(w->mlx.win, 3, 0, key_release, w);
	draw_map(w);
	mlx_put_image_to_window(w->mlx.init, w->mlx.win, w->mlx.img, 0, 0);
	mlx_loop(w->mlx.init);
}
