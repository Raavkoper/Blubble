/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:17:44 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/19 16:14:10 by rkoper        ########   odam.nl         */
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
