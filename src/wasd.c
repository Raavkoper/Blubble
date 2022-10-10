/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:41:20 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/10 11:39:58 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	input_data_up(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx + \
	data->cam.dirx * data->player.movespeed)] == '0')
		data->cam.posx += data->cam.dirx * data->player.movespeed;
	if (data->map.map[(int)(data->cam.posy + data->cam.diry * \
	data->player.movespeed)][(int)data->cam.posx] == '0')
		data->cam.posy += data->cam.diry * data->player.movespeed;
}

void	input_data_down(t_data *data)
{	
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx - \
	data->cam.dirx * data->player.movespeed)] == '0')
		data->cam.posx -= data->cam.dirx * data->player.movespeed;
	if (data->map.map[(int)(data->cam.posy - data->cam.diry * \
	data->player.movespeed)][(int)data->cam.posx] == '0')
		data->cam.posy -= data->cam.diry * data->player.movespeed;
}

void	input_data_left(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx - \
	data->cam.diry * data->player.movespeed)] == '0')
		data->cam.posx -= data->cam.diry * data->player.movespeed;
	if (data->map.map[(int)(data->cam.posy + data->cam.dirx * \
	data->player.movespeed)][(int)data->cam.posx] == '0')
	data->cam.posy += data->cam.dirx * data->player.movespeed;
}

void	input_data_right(t_data *data)
{
	if (data->map.map[(int)data->cam.posy][(int)(data->cam.posx + \
	data->cam.diry * data->player.movespeed)] == '0')
		data->cam.posx += data->cam.diry * data->player.movespeed;
	if (data->map.map[(int)(data->cam.posy - data->cam.dirx * \
	data->player.movespeed)][(int)data->cam.posx] == '0')
		data->cam.posy -= data->cam.dirx * data->player.movespeed;
}
