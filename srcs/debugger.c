/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:40:14 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/26 16:08:18 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	debug_message(t_w3d *w, int pos_y, char *info, char *value)
{
	char	*message;

	message = ft_strjoin(info, value);
	mlx_string_put(w->mlx.init, w->mlx.win, 50, pos_y, 0x75a557, message);
	free(message);
}

static int	degrees_to_angle(int angle)
{
	return (FT_ABS(angle % 360));
}

void		set_debug(t_w3d *w)
{
	char	*on;
	char	*off;
	char	*posx;
	char	*posy;
	char	*camera_angle;

	on = "Jaas";
	off = "Nein";
	posx = ft_itoa(w->cam.moveX);
	posy = ft_itoa(w->cam.moveY);
	camera_angle = ft_itoa(degrees_to_angle(w->cam.angle));
	debug_message(w, 30, "Angle :", camera_angle);
	debug_message(w, 50, "Up    :", (w->key.move_up == 1 ? on : off));
	debug_message(w, 70, "Down  :", (w->key.move_down == 1 ? on : off));
	debug_message(w, 90, "Left  :", (w->key.move_left == 1 ? on : off));
	debug_message(w, 110, "Right :", (w->key.move_right == 1 ? on : off));
	debug_message(w, 130, "Pos X :", posx);
	debug_message(w, 150, "Pos Y :", posy);
	free(posx);
	free(posy);
	free(camera_angle);
}