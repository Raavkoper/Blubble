/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:45:50 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/06 13:06:04 by svan-ass         ###   ########.fr       */
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
	{
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
					errorr("Error didnt rightfully specify the color");
				data->c_color = create_rgba(r, g, b, 255);
			}
			else
			{
				if (temp[0] != 'F' && temp[0] != 'C')
					errorr("Error didnt rightfully specify the color");
				data->f_color = create_rgba(r, g, b, 255);
			}
			i++;
			line = get_next_line(fd);
			free(temp);
		}
	}
	if (line[0] != '\n')
		errorr("Error whitespace error");
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
