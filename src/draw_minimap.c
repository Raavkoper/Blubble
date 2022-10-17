/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:45:59 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/17 14:37:44 by svan-ass         ###   ########.fr       */
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
			data->minimap.map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void	update_minimap(t_data *data)
{
	int		x;
	int		y;
	int		y2;
	int		x2;

	set_map_to_zero(data);
	y = 0;
	y2 = -7;
	while (y < 15)
	{
		x = 0;
		x2 = -7;
		while (x < 15)
		{
			if ((int)data->cam.posy + y2 > data->map.height \
			|| (int)data->cam.posx + x2 > data->map.width \
				|| (int)data->cam.posy + y2 < 0)
				break ;
			if (x == 0 || x == 14 || y == 0)
				data->minimap.map[y][x] = ' ';
			else if ((int)data->cam.posx + x2 >= 0 && \
			data->map.map[(int)data->cam.posy + \
			y2][(int)data->cam.posx + x2] != '\n')
				data->minimap.map[y][x] = data->map.map[(int)data->cam.posy \
				+ y2][(int)data->cam.posx + x2];
			x2++;
			x++;
		}
		y2++;
		y++;
	}
}

int	create_colors(int y2, int x2, t_data *data)
{
	int	color;

	if (y2 == 7 && x2 == 7)
		color = create_rgba(255, 105, 180, 255);
	else if (data->minimap.map[y2][x2] == '0')
		color = create_rgba(235, 190, 138, 255);
	else if (data->minimap.map[y2][x2] == '1')
		color = 0;
	else
		color = create_rgba(110, 109, 107, 255);
	return (color);
}

void	draw_minimap(t_data *data)
{	
	int	x;
	int	y;
	int	xhold;
	int	yhold;
	int	x2;
	int	y2;

	y = data->minimap.y_start;
	y2 = 0;
	while (y < data->minimap.y_end)
	{
		yhold = y;
		while (y < yhold + (data->minimap.height / 15))
		{
			x2 = 0;
			x = data->minimap.x_start;
			while (x < data->minimap.x_end)
			{	
				xhold = x;
				data->minimap.color = create_colors(y2, x2, data);
				while (x < xhold + (data->minimap.width / 15))
				{	
					mlx_put_pixel(data->g_img, x, y, data->minimap.color);
					x++;
				}
				x2++;
			}
			y++;
		}
		y2++;
	}
}
