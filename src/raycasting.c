/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:17:44 by rkoper        #+#    #+#                 */
/*   Updated: 2022/10/12 14:55:22 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

mlx_texture_t	*wall_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx < 0)
	{
		return (data->tex.we);
	}
	else if (data->ray.side == 1 && data->ray.raydiry > 0)
	{
		return (data->tex.so);
	}
	if (data->ray.side == 1)
		return (data->tex.no);
	else
		return (data->tex.ea);
}

void	raycasting(t_data *data)
{
	int				x;
	mlx_texture_t	*texture;

	x = 0;
	while (x < data->mlx->width)
	{
		init_raycasting(data, x);
		calculate_step_direction(data);
		check_for_wall_hit(data);
		calculate_perpwalldist(data);
		texture = wall_texture(data);
		calculate_textures(data);
		draw_walls(data, x, texture);
		x++;
	}
	update_minimap(data);
	draw_minimap(data);
}
