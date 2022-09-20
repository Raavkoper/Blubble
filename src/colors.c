/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 13:35:45 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/09/20 11:26:51 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	wall_colors(t_data *data)
{
	int	color;

	if (data->map.map[data->ray.mapy][data->ray.mapx] == '1')
	{
		color = create_rgba(6, 57, 112, 255);
		if (data->ray.side)
			color = create_rgba(7, 68, 125, 255);
	}
	if (data->map.map[data->ray.mapy][data->ray.mapx] == '2')
	{
		color = create_rgba(229, 116, 60, 255);
		if (data->ray.side)
			color = create_rgba(209, 100, 43, 255);
	}
	if (data->map.map[data->ray.mapy][data->ray.mapx] == '3')
	{
		color = create_rgba(204, 206, 204, 255);
		if (data->ray.side)
			color = create_rgba(78, 179, 242, 255);
	}
	if (data->map.map[data->ray.mapy][data->ray.mapx] == '4')
	{
		color = create_rgba(198, 132, 96, 255);
		if (data->ray.side)
			color = create_rgba(155, 51, 25, 255);
	}
	return (color);
}
