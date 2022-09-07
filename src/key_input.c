/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:10:43 by svan-ass          #+#    #+#             */
/*   Updated: 2022/09/06 12:08:34 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	keys(struct mlx_key_data keys, void *param)
{
	t_data	*data;
	double	olddirx;
	double	oldplanex;

	data = (t_data *)param;
	olddirx = data->raycasting.dirx;
	oldplanex = data->raycasting.planex;
	if (keys.key == MLX_KEY_UP)
	{
		printf("go up\n");
		printf("posx: %f posy: %f\n", data->player.posx, data->player.posy);
		data->player.posx += data->raycasting.dirx;
		data->player.posy += data->raycasting.diry;
	}
	if (keys.key == MLX_KEY_DOWN)
	{
		printf("go down\n");
		printf("posx: %f posy: %f\n", data->player.posx, data->player.posy);
		data->player.posx -= data->raycasting.dirx;
		data->player.posy -= data->raycasting.diry;
	}
	if (keys.key == MLX_KEY_LEFT)
	{
		data->raycasting.dirx = data->raycasting.dirx * cos(data->raycasting.rotspeed) - data->raycasting.diry * sin(-data->raycasting.rotspeed);
		data->raycasting.diry = olddirx * sin(-data->raycasting.rotspeed) + data->raycasting.diry * cos(-data->raycasting.rotspeed);
		data->raycasting.planex = data->raycasting.planex * cos(-data->raycasting.rotspeed) - data->raycasting.planey * sin(-data->raycasting.rotspeed);
		data->raycasting.planey = oldplanex * sin(-data->raycasting.rotspeed) + data->raycasting.planey * cos(-data->raycasting.rotspeed);
	}
	raycasting(data);
}

void	key_input(t_data *data)
{
	double	time = 0;
	double	oldtime = 0;
	double	frametime;
	t_data	*temp;

	temp = data;
	oldtime = time;
	time = clock();
	frametime = (time - oldtime) / 1000.0;
	printf("%f\n", (1.0 / frametime));

	data->player.movespeed = frametime * 3.0;
	data->raycasting.rotspeed = frametime * 2.0;
	mlx_key_hook(data->mlx, keys, data);
}
