/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:31:58 by rkoper            #+#    #+#             */
/*   Updated: 2022/09/29 11:17:08 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	loading_textures(t_data *data)
{
	data->tex.texture1 = mlx_load_png("textures/texture1.png");
	data->xpm->texture = mlx_load_png("textures/texture1.png");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Incorrect number of arguments\n");
		return (1);
	}
	data.mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "Blubble", false);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.g_img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.map_file = argv[1];
	read_map(&data);
	init_camera(&data);
	draw_f_c(&data, data.c_color, 'c');
	draw_f_c(&data, data.f_color, 'f');
	loading_textures(&data);
	raycasting(&data);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	mlx_loop_hook(data.mlx, start, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
