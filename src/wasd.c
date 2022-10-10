/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:20 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/06 12:42:15 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	input_data_up(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx + \
	data->cam.dirx * 0.03)] == '0')
		data->cam.posx += data->cam.dirx * 0.03;
	if (data->map.map[(int)(data->cam.posy + data->cam.diry * \
	0.03)][(int)data->cam.posx] == '0')
		data->cam.posy += data->cam.diry * 0.03;
}

void	input_data_down(t_data *data)
{	
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx - \
	data->cam.dirx * 0.03)] == '0')
		data->cam.posx -= data->cam.dirx * 0.03;
	if (data->map.map[(int)(data->cam.posy - data->cam.diry * \
	0.03)][(int)data->cam.posx] == '0')
		data->cam.posy -= data->cam.diry * 0.03;
}

void	input_data_left(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx - \
	data->cam.diry * 0.03)] == '0')
		data->cam.posx -= data->cam.diry * 0.03;
	if (data->map.map[(int)(data->cam.posy + data->cam.dirx * \
	0.03)][(int)data->cam.posx] == '0')
	data->cam.posy += data->cam.dirx * 0.03;
}

void	input_data_right(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx + \
	data->cam.diry * 0.03)] == '0')
		data->cam.posx += data->cam.diry * 0.03;
	if (data->map.map[(int)(data->cam.posy - data->cam.dirx * \
	0.03)][(int)data->cam.posx] == '0')
		data->cam.posy -= data->cam.dirx * 0.03;
}
