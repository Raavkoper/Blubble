/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:39:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/26 13:54:32 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	read_map(t_data *data)
{
	int	fd;

	fd = open(data->map_file, O_RDONLY);
	error_map(data, fd);
	fd = open(data->map_file, O_RDONLY);
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
		temp = line;
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	if (line[0] != '\n')
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
			if ((line[j] == 'N' || line[j] == 'E' \
				|| line[j] == 'S' || line[j] == 'W'))
			{
				data->cam.posx = j + 1;
				data->cam.posy = i + 1;
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
	close(fd);
}

void	allocate_map(t_map *map, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(data->map_file, O_RDONLY);
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
	set_textures(data, fd);
	color_map(data, fd);
	parse_map(&data->map, fd, data);
}
