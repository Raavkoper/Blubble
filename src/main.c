/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:31:58 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/29 13:13:04 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.xpm.texture = *mlx_load_png("textures/texture1.png");
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
	raycasting(&data);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	mlx_loop_hook(data.mlx, start, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
