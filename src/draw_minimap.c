/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:45:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/12 15:09:58 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	set_map_to_zero(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < 14)
	{
		x = 0;
		while (x < 14)
		{
			data->minimap.map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void	print_map(char map[15][15], t_data *data)
{
	int x = 0;
	int y = 0;

	while (y < 14)
	{
		x = 0;
		while (x < 14)
		{
			if (y == 7 && x == 7)
				printf("P");
			else
				printf("%c", map[y][x]);
			x++;
		}	
		y++;
		printf("\n");
	}
}

void	update_minimap(t_data *data)
{
	int x;
	int y;
	int y2;
	int x2;
	char **map;
	
	set_map_to_zero(data);
	y = 0;
	map = data->map.map;
	y2 = -7;
	while (y < 14)
	{
		x = 0;
		x2 = -7;
		while (x < 14)
		{
			if ((int)data->cam.posy + y2 > data->map.height || (int)data->cam.posx + x2 > data->map.width \
				|| (int)data->cam.posy + y2 < 0 || (int)data->cam.posx + x2 < 0)
				break ;
			else
				data->minimap.map[y][x] = map[(int)data->cam.posy + y2][(int)data->cam.posx + x2];
			x2++;
			x++;
		}
		y2++;
		y++;
	}
	// print_map(data->minimap.map, data);
	// printf("\n\n\n");
}

void	draw_minimap(t_data *data)
{	
	int x;
	int y;
	int xhold;
	int yhold;
	int x2;
	int y2;
	int empty;
	int wall;
	int player;
	int color;
	
	player = create_rgba(255, 172, 28, 255);
	wall = create_rgba(0, 71, 171, 255);
	empty = create_rgba(137, 207, 240, 255);
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
				if (y2 == 7 && x2 == 7)
					color = player;
				else if (data->minimap.map[y2][x2] == '1')
				{
					color = wall;
				}
				else if (data->minimap.map[y2][x2] == '0')
					color = empty;
				while (x < xhold + (data->minimap.width / 15))
				{	
					*(uint32_t *)(data->g_img->pixels + \
					((y * data->g_img->width + x) * 4)) = color;
					x++;
				}
				x2++;
			}
			y++;
		}
		y2++;
	}
}