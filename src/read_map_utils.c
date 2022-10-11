/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:38:48 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/11 13:23:08 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	check_width_height(t_map *map, int fd, char *line)
{
	int	height;
	int	width;
	int	max;

	height = 0;
	max = 0;
	while (line)
	{
		width = map_strlen(line);
		if (width > max)
			max = width;
		free(line);
		line = get_next_line(fd);
		height++;
	}
	map->width = max;
	map->height = height;
}
