/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:18:34 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/14 15:45:31 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	wall_texture_no(t_data *data, char *str)
{
	if (!(ft_strncmp(str, "textures/texture2.png", 22)))
		data->no_wall = 'F';
	data->tex.no = mlx_load_png(str);
	if (data->tex.no == 0)
		errorr("Error no valid textures path");
	data->map.no += 1;
}

void	wall_texture_so(t_data *data, char *str)
{
	if (!(ft_strncmp(str, "textures/texture2.png", 22)))
		data->so_wall = 'F';
	data->tex.so = mlx_load_png(str);
	if (data->tex.so == 0)
		errorr("Error no valid textures path");
	data->map.so += 1;
}

void	wall_texture_we(t_data *data, char *str)
{	
	if (!(ft_strncmp(str, "textures/texture2.png", 22)))
		data->we_wall = 'F';
	data->tex.we = mlx_load_png(str);
	if (data->tex.we == 0)
		errorr("Error no valid textures path");
	data->map.we += 1;
}

void	wall_texture_ea(t_data *data, char *str)
{
	if (!(ft_strncmp(str, "textures/texture2.png", 22)))
		data->ea_wall = 'F';
	data->tex.ea = mlx_load_png(str);
	if (data->tex.ea == 0)
		errorr("Error no valid textures path");
	data->map.ea += 1;
}
