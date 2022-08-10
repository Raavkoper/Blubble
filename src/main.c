/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:31:58 by rkoper        #+#    #+#                 */
/*   Updated: 2022/08/10 11:21:40 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
		read_map(&data, argv[1]);
	else
		printf("no given map input ofz\n");
	print_map(data.map);
	// data.mlx = mlx_init(1000, 1000, "MLX42", true);
	// if (!data.mlx)
	// 	exit(EXIT_FAILURE);
	// data.g_img = mlx_new_image(data.mlx, 128, 128);
	// memset(data.g_img->pixels, 255, data.g_img->width * data.g_img->height \
	// * sizeof(int));
	// mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	// mlx_loop_hook(data.mlx, &hook, data.mlx);
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
