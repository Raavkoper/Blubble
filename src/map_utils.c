/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:45:50 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/11 11:33:57 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

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

void	elements(t_data *data, int fd, int line_count)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line_count < 6)
	{
		if (line[0] != 'N' && line[0] != 'S' && \
		line[0] != 'E' && line[0] != 'W' && \
		line[0] != 'F' && line[0] != 'C' && \
		line[0] != '\n' && line[0] != '\0')
			errorr("Error no valid (color) path");
		else if (line[0] == 'N' || line[0] == 'S' \
		|| line[0] == 'E' || line[0] == 'W')
			line_count += safe_wall_textures(data, line);
		else if (line[0] == 'F' || line[0] == 'C')
		{
			check_floor_ceiling(data, line, fd);
			line_count += 1;
		}
		temp = line;
		line = get_next_line(fd);
		free(temp);
		data->start_map_line += 1;
	}
	double_check_map(data);
	free(line);
}
