/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 11:50:46 by khakala           #+#    #+#             */
/*   Updated: 2021/05/26 14:24:10 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		get_height(char *file_name, t_w3d *w)
{
	int			i;
	int			fd;
	int			height;
	char		*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
		{
			w->grid.width = ft_count_words(line, ' ');
			i++;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		ft_count_words(const char *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

void	fill_matrix(int *z_line, char *line, t_w3d *w)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		check_outer_bounder(z_line, i, w);
		free(nums[i]);
		i++;
	}
	w->grid.row++;
	free(nums);
}

void	check_outer_bounder(int *z_line, int i, t_w3d *w)
{
	if (w->grid.row == 0 || (w->grid.height - 1) == w->grid.row)
		z_line[i] = 1;
	if (i == 0 || (w->grid.width - 1) == i)
		z_line[i] = 1;
}

void	read_map(char *file_name, t_w3d *w)
{
	int		i;
	int		fd;
	char	*line;

	w->grid.height = get_height(file_name, w);
	w->grid.matrix = (int**)malloc(sizeof(int) * (w->grid.width + 1));
	i = 0;
	while (i <= w->grid.height)
		w->grid.matrix[i++] = (int*)malloc(sizeof(int) * (w->grid.width + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i < w->grid.height)
		{
			fill_matrix(w->grid.matrix[i], line, w);
			i++;
		}
		free(line);
	}
	close(fd);
}
