/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 14:10:43 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/09/19 16:14:30 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	movement(t_data *data)
{	
	double	olddirx;
	double	olddiry;
	double	oldplanex;

	olddirx = data->cam.dirx;
	oldplanex = data->cam.planex;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->cam.posy += data->cam.diry * 0.03;
		data->cam.posx += data->cam.dirx * 0.03;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->cam.posy -= data->cam.diry * 0.03;
		data->cam.posx -= data->cam.dirx * 0.03;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->cam.dirx = data->cam.dirx * cos(-data->cam.rotspeed) - data->cam.diry * sin(-data->cam.rotspeed);
		data->cam.diry = olddirx * sin(-data->cam.rotspeed) + data->cam.diry * cos(-data->cam.rotspeed);
		data->cam.planex = data->cam.planex * cos(-data->cam.rotspeed) - \
		data->cam.planey * sin(-data->cam.rotspeed);
		data->cam.planey = oldplanex * sin(-data->cam.rotspeed) + data->cam.planey * cos(-data->cam.rotspeed);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->cam.dirx = data->cam.dirx * cos(data->cam.rotspeed) - data->cam.diry * sin(data->cam.rotspeed);
		data->cam.diry = olddirx * sin(data->cam.rotspeed) + data->cam.diry * cos(data->cam.rotspeed);
		data->cam.planex = data->cam.planex * cos(data->cam.rotspeed) - \
		data->cam.planey * sin(data->cam.rotspeed);
		data->cam.planey = oldplanex * sin(data->cam.rotspeed) + data->cam.planey * cos(data->cam.rotspeed);
	}
}

// void	key_input(t_data *data)
// {
// 	double	time = 0;
// 	double	oldtime = 0;
// 	double	frametime;

// 	oldtime = time;
// 	time = clock();
// 	frametime = (time - oldtime) / 1000.0;

// 	data->cam.rotspeed = frametime * 2.0;
// 	mlx_key_hook(data->mlx, movement, data);
// }
