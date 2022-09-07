/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:10:43 by svan-ass          #+#    #+#             */
/*   Updated: 2022/09/07 14:39:10 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	movement(struct mlx_key_data keycode, void *param)
{	
	t_data	*data;
	double	olddirx;
	double	oldplanex;

	data = (t_data *)param;
	olddirx = data->cam.dirx;
	oldplanex = data->cam.planex;
	keycode.key = MLX_KEY_W;
	if (mlx_is_key_down(data->mlx, keycode.key))
	{
		if (worldMap[(int)data->cam.posx + 1][(int)data->cam.posy] == 0)
		{
			printf("up -> posx: %f posy: %f\n", data->cam.posx, data->cam.posy);
			data->cam.posx += data->cam.dirx;
		}
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) == true)
	{
		printf("left -> posx: %f posy: %f\n", data->cam.posx, data->cam.posy);
		data->cam.dirx = data->cam.dirx * cos(data->cam.rotspeed) - data->cam.diry * sin(data->cam.rotspeed);
		data->cam.diry = olddirx * sin(data->cam.rotspeed) + data->cam.diry * cos(data->cam.rotspeed);
		data->cam.planex = data->cam.planex * cos(data->cam.rotspeed) - \
		data->cam.planey * sin(data->cam.rotspeed);
		data->cam.planey = oldplanex * sin(data->cam.rotspeed) + data->cam.planey * cos(data->cam.rotspeed);
	}
	raycasting(data);
}

void	key_input(t_data *data)
{
	double	time = 0;
	double	oldtime = 0;
	double	frametime;

	oldtime = time;
	time = clock();
	frametime = (time - oldtime) / 1000.0;
	printf("%f\n", (1.0 / frametime));

	data->cam.rotspeed = frametime * 2.0;
	mlx_key_hook(data->mlx, movement, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) == true)
	{
		printf("go up\n");
		printf("posx: %f posy: %f\n", data->cam.posx, data->cam.posy);
		data->cam.posx += data->cam.dirx;
		data->cam.posy += data->cam.diry;
	}
}
