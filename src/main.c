/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:31:58 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/17 14:15:53 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		errorr("Incorrect number of arguments");
	data.mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "Blubble", false);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.g_img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.map_file = argv[1];
	init_data(&data);
	read_map(&data);
	draw_f_c(&data, data.c_color, 'c');
	draw_f_c(&data, data.f_color, 'f');
	load_textures(&data);
	raycasting(&data);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	mlx_loop_hook(data.mlx, start, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
