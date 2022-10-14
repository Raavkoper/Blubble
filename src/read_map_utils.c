/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:38:48 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/12 11:05:20 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	copy_map_2(t_map *map, char c, int *k, int i)
{
	if (c == '\t')
	{
		map->map[i][*k] = ' ';
		map->map[i][*k + 1] = ' ';
		map->map[i][*k + 2] = ' ';
		map->map[i][*k + 3] = ' ';
		*k += 3;
	}
	else if (c == '0' || ft_isdigit(c) \
		|| c == ' ' || c == '\n')
		map->map[i][*k] = c;
	else if (c != 'N' && c != 'E' && c != 'S' && c != 'W')
		errorr("Error unregconized character in the map");
	*k += 1;
}

void	set_player_pos(t_data *data, int i, int j, int k)
{
	data->cam.posx = j + 0.5;
	data->cam.posy = i + 0.5;
	data->map.map[i][k] = '0';
	if (data->map.pos_count)
		errorr("Error multiple starting positions set");
	data->map.pos_count += 1;
}

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
