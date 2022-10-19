/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:45:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/19 11:42:13 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	set_map_to_zero(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 15)
	{
		x = 0;
		while (x < 15)
		{
			data->mm.map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

int	update_map_util(t_data *data, int x[2], int y[2])
{
	if ((int)data->cam.posy + y[1] > data->map.height \
	|| (int)data->cam.posx + x[1] > data->map.width \
		|| (int)data->cam.posy + y[1] < 0)
		return (1);
	if (x[0] == 0 || x[0] == 14 || y[0] == 0)
		data->mm.map[y[0]][x[0]] = ' ';
	else if ((int)data->cam.posx + x[1] >= 0 && \
	data->map.map[(int)data->cam.posy + \
	y[1]][(int)data->cam.posx + x[1]] != '\n')
		data->mm.map[y[0]][x[0]] = data->map.map[(int)data->cam.posy \
		+ y[1]][(int)data->cam.posx + x[1]];
	return (0);
}

void	update_minimap(t_data *data)
{
	int		x[2];
	int		y[2];

	set_map_to_zero(data);
	y[0] = 0;
	y[1] = -7;
	while (y[0] < 15)
	{
		x[0] = 0;
		x[1] = -7;
		while (x[0] < 15)
		{
			if (update_map_util(data, x, y))
				break ;
			x[1]++;
			x[0]++;
		}
		y[1]++;
		y[0]++;
	}
}

int	create_colors(int y2, int x2, t_data *data)
{
	int	color;

	if (y2 == 7 && x2 == 7)
		color = create_rgba(255, 105, 180, 255);
	else if (data->mm.map[y2][x2] == '0')
		color = create_rgba(235, 190, 138, 255);
	else if (data->mm.map[y2][x2] == '1')
		color = 0;
	else
		color = create_rgba(110, 109, 107, 255);
	return (color);
}

void	draw_minimap(t_data *data)
{	
	data->mm.y = data->mm.y_start;
	data->mm.y2 = 0;
	while (data->mm.y < data->mm.y_end)
	{
		data->mm.yhold = data->mm.y;
		while (data->mm.y < data->mm.yhold + (data->mm.height / 15))
		{
			data->mm.x2 = 0;
			data->mm.x = data->mm.x_start;
			while (data->mm.x < data->mm.x_end)
			{	
				data->mm.xhold = data->mm.x;
				data->mm.color = create_colors(data->mm.y2, data->mm.x2, data);
				while (data->mm.x < data->mm.xhold + (data->mm.width / 15))
				{
					mlx_put_pixel(data->g_img, data->mm.x, \
						data->mm.y - 10, data->mm.color);
					data->mm.x++;
				}
				data->mm.x2++;
			}
			data->mm.y++;
		}
		data->mm.y2++;
	}
}
