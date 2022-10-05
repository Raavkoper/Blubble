/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:39:59 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/05 15:33:53 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	read_map(t_data *data)
{
	int	fd;

	fd = open(data->map_file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
	{
		printf("Error failed opening the map file\n");
		exit(1);
	}
	init_map(data, fd);
}

void	set_textures(t_data *data, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (i < 4)
	{
		safe_wall_textures(data, line);
		temp = line;
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	if (line[0] != '\n' || !line[0])
	{
		printf("Error whitespace error\n");
		exit(1);
	}
	free(line);
}

int	map_strlen(char const *str)
{
	int	i;
	int	ret;

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

int	check_player_direction(t_data *data, char *line, int j)
{
	if (line[j] == 'N' || line[j] == 'E' \
	|| line[j] == 'S' || line[j] == 'W')
	{
		if (line[j] == 'N')
			data->cam.diry = -1;
		else if (line[j] == 'S')
			data->cam.diry = +1;
		else if (line[j] == 'E')
			data->cam.dirx = +1;
		else if (line[j] == 'W')
			data->cam.dirx = -1;
		data->cam.planex = tan(M_PI_2 * 70 / 180.0) * -data->cam.diry;
		data->cam.planey = tan(M_PI_2 * 70 / 180.0) * data->cam.dirx;
		return (1);
	}
	return (0);
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
				{
					printf("Error multiple starting positions set\n");
					exit(1);
				}
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
			{
				printf("Error unregconized character in the map\n");
				exit(1);
			}
			j++;
			k++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!pos_count)
	{
		printf("Error no player position set\n");
		exit(1);
	}
	close(fd);
}

void	allocate_map(t_map *map, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(data->map_file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
	{
		printf("Error failed opening the map file\n");
		exit(1);
	}
	map->map = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	while (i <= map->height)
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
	copy_map(map, fd, data);
}

void	parse_map(t_map *map, int fd, t_data *data)
{
	char	*line;
	int		height;
	int		width;
	int		max;

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
	close(fd);
	allocate_map(map, data);
}

void	color_map(t_data *data, int fd)
{
	char	*line;
	char	*temp;
	int		i;
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	i = 0;
	line = get_next_line(fd);
	if (line[0] != '\n')
	while (i < 2)
	{
		temp = line;
		while (*line && !ft_isdigit(*line))
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
		{
			if (temp[0] != 'F' && temp[0] != 'C')
			{
				printf("Error didnt rightfully specify the color\n");
				exit(1);
			}
			data->c_color = create_rgba(r, g, b, 255);
		}
		else
		{
			if (temp[0] != 'F' && temp[0] != 'C')
			{
				printf("Error didnt rightfully specify the color\n");
				exit(1);
			}
			data->f_color = create_rgba(r, g, b, 255);
		}
		i++;
		line = get_next_line(fd);
		free(temp);
	}
	if (line[0] != '\n')
	{
		printf("Error whitespace error\n");
		exit(1);
	}
	free(line);
}

void	draw_f_c(t_data *data, uint32_t	color, char c)
{
	int			x;
	int			y;
	int			end;

	if (c == 'f')
		y = 0;
	else
		y = SCREENHEIGHT / 2;
	end = y + (SCREENHEIGHT / 2);
	while (y < end)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			mlx_put_pixel(data->g_img, x, y, color);
			x++;
		}
		y++;
	}
}

void	init_map(t_data *data, int fd)
{
	cub_extension_check(data->map_file);
	set_textures(data, fd);
	color_map(data, fd);
	parse_map(&data->map, fd, data);
	check_closed_walls(data->map);
}
