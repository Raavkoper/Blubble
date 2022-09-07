/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:31:58 by rkoper            #+#    #+#             */
/*   Updated: 2022/09/07 10:14:13 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	initilize_data(t_data *data)
{
	data->player.posx = 14;
	data->player.posy = 8;
	data->raycasting.dirx = -1;
	data->raycasting.diry = 0;
	data->raycasting.planex = 0;
	data->raycasting.planey = 0.66;
}

void	hook(void *param)
{	
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		printf("Incorrect number of arguments\n");
	read_map(&data, argv[1]);
	data.mlx = mlx_init(screenWidth, screenHeight, "Blubble", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.g_img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	// memset(data.g_img->pixels, 255, data.g_img->width * data.g_img->height \
	// * sizeof(int));
	// draw_floor(&data);
	// draw_ceiling(&data);
	initilize_data(&data);
	raycasting(&data);
	key_input(&data);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	mlx_loop_hook(data.mlx, &hook, data.mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
