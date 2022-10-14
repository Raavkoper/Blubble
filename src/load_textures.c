/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:30:37 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/14 15:43:32 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	load_fish_tex(t_data *data)
{
	data->tex.fish[0] = mlx_load_png("textures/texture2.png");
	data->tex.fish[1] = mlx_load_png("textures/fish/fish2.png");
	data->tex.fish[2] = mlx_load_png("textures/fish/fish3.png");
	data->tex.fish[3] = mlx_load_png("textures/fish/fish4.png");
	data->tex.fish[4] = mlx_load_png("textures/fish/fish5.png");
	data->tex.fish[5] = mlx_load_png("textures/fish/fish6.png");
	data->tex.fish[6] = mlx_load_png("textures/fish/fish7.png");
	data->tex.fish[7] = mlx_load_png("textures/fish/fish8.png");
	data->tex.fish[8] = mlx_load_png("textures/fish/fish9.png");
	data->tex.fish[9] = mlx_load_png("textures/fish/fish10.png");
	data->tex.fish[10] = mlx_load_png("textures/fish/fish11.png");
	data->tex.fish[11] = mlx_load_png("textures/fish/fish12.png");
	data->tex.fish[12] = mlx_load_png("textures/fish/fish13.png");
}

void	load_textures(t_data *data)
{
	load_fish_tex(data);
}
