/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:17:44 by rkoper            #+#    #+#             */
/*   Updated: 2022/09/27 10:23:46 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	raycasting(t_data *data)
{
	int	x;
	int	color;

	x = 0;
	while (x < data->mlx->width)
	{
		init_raycasting(data, x);
		calculate_step_direction(data);
		check_for_wall_hit(data);
		calculate_perpwalldist(data);
		color = wall_colors(data);
		calculate_textures(data);
		draw_walls(data, x, color);
		x++;
	}
}
