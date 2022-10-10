/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:30:47 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/06 12:43:22 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	init_camera(t_data *data)
{
	data->cam.planex = 0;
	data->cam.planey = 0.66;
	data->cam.dirx = -1;
	data->cam.diry = 0;
}

void	init_raycasting(t_data *data, int x)
{
	data->cam.camerax = 2 * x / (double)data->mlx->width - 1;
	data->ray.raydirx = data->cam.dirx + data->cam.planex * data->cam.camerax;
	data->ray.raydiry = data->cam.diry + data->cam.planey * data->cam.camerax;
	data->ray.mapx = (int)data->cam.posx;
	data->ray.mapy = (int)data->cam.posy;
	data->ray.hit = 0;
	if (data->ray.raydirx == 0)
		data->ray.raydirx = 1e30;
	else
		data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.raydiry = 1e30;
	else
		data->ray.deltadisty = fabs(1 / data->ray.raydiry);
}
