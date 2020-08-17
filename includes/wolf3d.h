/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:43 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/08/17 13:53:05 by lsjoberg         ###   ########.fr       */
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

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_img
{
	char	*data;
	int		size;
	int		endian;
	int		pxc;
}				t_img;

typedef struct s_w3d
{
	t_mlx	mlx;
	t_img	img;
}				t_w3d;




#endif