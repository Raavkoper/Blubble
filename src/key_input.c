/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 14:10:43 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/10/07 13:53:30 by rkoper        ########   odam.nl         */
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

void	input_data_rotate_left(t_data *data)
{
	double	olddirx;
	double	olddiry;
	double	oldplanex;

	olddirx = data->cam.dirx;
	oldplanex = data->cam.planex;
	data->cam.dirx = data->cam.dirx * cos(-data->cam.rotspeed) - \
	data->cam.diry * sin(-data->cam.rotspeed);
	data->cam.diry = olddirx * sin(-data->cam.rotspeed) + \
	data->cam.diry * cos(data->cam.rotspeed);
	data->cam.planex = data->cam.planex * cos(-data->cam.rotspeed) - \
	data->cam.planey * sin(-data->cam.rotspeed);
	data->cam.planey = oldplanex * sin(-data->cam.rotspeed) + \
	data->cam.planey * cos(-data->cam.rotspeed);
}

void	input_data_rotate_right(t_data *data)
{
	double	olddirx;
	double	olddiry;
	double	oldplanex;

	olddirx = data->cam.dirx;
	oldplanex = data->cam.planex;
	data->cam.dirx = data->cam.dirx * cos(data->cam.rotspeed) - \
	data->cam.diry * sin(data->cam.rotspeed);
	data->cam.diry = olddirx * sin(data->cam.rotspeed) + \
	data->cam.diry * cos(data->cam.rotspeed);
	data->cam.planex = data->cam.planex * cos(data->cam.rotspeed) - \
	data->cam.planey * sin(data->cam.rotspeed);
	data->cam.planey = oldplanex * sin(data->cam.rotspeed) + \
	data->cam.planey * cos(data->cam.rotspeed);
}


void	key_input(t_data *data)
{	
	double	olddirx;
	double	olddiry;
	double	oldplanex;

	olddirx = data->cam.dirx;
	oldplanex = data->cam.planex;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		input_data_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		input_data_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		input_data_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		input_data_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		input_data_rotate_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		input_data_rotate_right(data);
	data->player.movespeed = 0.03;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		data->player.movespeed = 0.06;
}
