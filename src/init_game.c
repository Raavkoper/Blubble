/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:41 by rkoper            #+#    #+#             */
/*   Updated: 2022/08/02 11:13:26 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("no puedo mlx\n");
	}
	data->map = NULL;
}

void	create_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Blubble");
	if (!data->win)
	{
		printf("no puedo window\n");
		exit(1);
	}
	data->image.img = mlx_new_image(data->mlx, 1920, 1080);
	data->image.addr = mlx_get_data_addr(data->image.img, \
	&data->image.bits_per_pixel, &data->image.line_length, &data->image.endian);
}