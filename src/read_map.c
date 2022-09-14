/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:39:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/07 14:50:46 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	read_map(t_data *data)
{
	int fd;

	fd = open(data->file, O_RDONLY);
	init_map(data, fd);
}

void	set_textures(t_data *data, int fd)
{
	int i;
	char *line;
	char *temp;
	
	i = 0;
	line = get_next_line(fd);
	while (i < 4)
	{
		temp = line;
		line = get_next_line(fd);
		free(temp);
		i++;
	}
}

int	map_strlen(char const *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			ret += 3;
		i++;
		ret++;
	}
	return (ret);
}

void	copy_map(t_map *map, int fd)
{
	char *line;
	int i;
	int j;
	
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		j = 0;
		while (line[j])
		{
			map->map[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < 15)
	{
		printf("%s", map->map[i]);
		i++;
	}
}

void	allocate_map(t_map *map, char *file)
{
	int i;
	int fd;
	char *line;
	
	fd = open(file, O_RDONLY);
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	while (i <= map->height + 3)
	{
		map->map[i] = ft_calloc(map->width + 1, sizeof(char));
		i++;
	}
	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	copy_map(map, fd);
}

void	parse_map(t_map *map, int fd, char *file)
{
	char *line;
	int height;
	int width;
	int max;

	line = get_next_line(fd);
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
	allocate_map(map, file);
}

void	color_map(t_data *data, int fd)
{
	char *line;
	int i;
	char *temp;
	int r = 0;
	int g = 0;
	int b = 0;
	
	line = get_next_line(fd);
	i = 0;
	while (i < 2)
	{
		temp = line;
		while (!ft_isdigit(*line))
			line++;
		r = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (!ft_isdigit(*line))
			line++;
		g = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (!ft_isdigit(*line))
			line++;
		b = ft_atoi(line);
		if (!i)
			draw_f_c(data, create_rgba(r, g, b, 255), 'c');
		else
			draw_f_c(data, create_rgba(r, g, b, 255), 'f');
		i++;
		line = get_next_line(fd);
		free(temp);
	}
}

void	init_map(t_data *data, int fd)
{
	set_textures(data, fd);
	color_map(data, fd);
	parse_map(&data->map, fd, data->file);
}
