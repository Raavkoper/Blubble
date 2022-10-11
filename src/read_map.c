/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:39:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/11 11:49:57 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	read_map(t_data *data)
{
	int	fd;

	fd = open(data->map_file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		errorr("Error failed opening the map file");
	init_map(data, fd);
}

void	copy_map(t_map *map, int fd, t_data *data)
{
	char	*line;
	int		i;
	int		j;
	int		k;
	int		pos_count;

	line = get_next_line(fd);
	i = 0;
	pos_count = 0;
	while (line)
	{
		j = 0;
		k = 0;
		while (line[j])
		{
			if ((check_player_direction(data, line, j)))
			{
				data->cam.posx = j + 0.5;
				data->cam.posy = i + 0.5;
				map->map[i][k] = '0';
				if (pos_count)
					errorr("Error multiple starting positions set\n");
				pos_count++;
			}
			else if (line[j] == '\t')
			{
				map->map[i][k] = ' ';
				map->map[i][k + 1] = ' ';
				map->map[i][k + 2] = ' ';
				map->map[i][k + 3] = ' ';
				k += 3;
			}
			else if (line[j] == '0' || ft_isdigit(line[j]) \
				|| line[j] == ' ' || line[j] == '\n')
				map->map[i][k] = line[j];
			else
				errorr("Error unregconized character in the map");
			j++;
			k++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!pos_count)
		errorr("Error no player position set");
	close(fd);
}

void	allocate_map(t_map *map, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(data->map_file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		errorr("Error failed opening the map file");
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	while (i <= map->height)
	{
		map->map[i] = ft_calloc(map->width + 1, sizeof(char));
		i++;
	}
	i = 0;
	while (i < data->start_map_line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	copy_map(map, fd, data);
}

void	parse_map(t_map *map, int fd, t_data *data)
{
	char	*line;
	char	*temp;
	int		height;
	int		width;
	int		max;

	line = get_next_line(fd);
	while (line[0] == '\n' || line[0] == '\0')
	{
		temp = line;
		line = get_next_line(fd);
		free(temp);
		data->start_map_line += 1;
	}
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
	close(fd);
	allocate_map(map, data);
}

void	init_map(t_data *data, int fd)
{
	int	line_count;

	line_count = 0;
	cub_extension_check(data->map_file);
	elements(data, fd, line_count);
	parse_map(&data->map, fd, data);
	check_closed_walls(data->map);
}
