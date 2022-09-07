/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:31:58 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/07 14:03:28 by rkoper        ########   odam.nl         */
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

	if (argc != 2)
	{
		printf("no given map input ofz\n");
		exit(1);
	}
	data.file = argv[1];
	data.mlx = mlx_init(screenWidth, screenHeight, "Blubble", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.g_img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	read_map(&data);
	raycasting(&data);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	mlx_loop_hook(data.mlx, &hook, data.mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
