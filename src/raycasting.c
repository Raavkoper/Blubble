/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:17:44 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/19 11:47:37 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

mlx_texture_t	*wall_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx < 0)
	{
		if (data->we_wall == 'F')
			return (load_fish(data));
		return (data->tex.we);
	}
	else if (data->ray.side == 1 && data->ray.raydiry > 0)
	{
		if (data->so_wall == 'F')
			return (load_fish(data));
		return (data->tex.so);
	}
	else if (data->ray.side == 1)
	{
		if (data->no_wall == 'F')
			return (load_fish(data));
		return (data->tex.no);
	}
	else
	{
		if (data->ea_wall == 'F')
			return (load_fish(data));
		return (data->tex.ea);
	}
	return (0);
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
