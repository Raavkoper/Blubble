/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:30:47 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/14 14:34:31 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	init_data(t_data *data)
{
	data->player.movespeed = 0.03;
	data->start_map_line = 1;
	data->map.pos_count = 0;
	data->map.no = 0;
	data->map.so = 0;
	data->map.we = 0;
	data->map.ea = 0;
	data->map.f = 0;
	data->map.c = 0;
	data->no_wall = 'A';
	data->so_wall = 'A';
	data->we_wall = 'A';
	data->ea_wall = 'A';
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
