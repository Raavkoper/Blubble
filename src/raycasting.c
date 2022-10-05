/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:17:44 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/05 15:25:37 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

mlx_texture_t	*wall_texture(t_data *data)
{
	if (data->ray.side == 0)
	{
		return (data->tex.tex1);
	}
	else
	{
		return (data->tex.tex2);
	}
}

void	raycasting(t_data *data)
{
	int				x;
	int				color;
	mlx_texture_t	*texture;

	x = 0;
	while (x < data->mlx->width)
	{
		init_raycasting(data, x);
		calculate_step_direction(data);
		check_for_wall_hit(data);
		calculate_perpwalldist(data);
		color = wall_colors(data);
		texture = wall_texture(data);
		calculate_textures(data);
		draw_walls(data, x, texture);
		x++;
	}
}
