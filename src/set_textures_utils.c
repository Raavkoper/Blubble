/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_textures_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:18:34 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/10/12 10:30:52 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	wall_texture_no(t_data *data, char *str)
{
	if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.no = mlx_load_png("textures/texture1.png");
	else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
		data->tex.no = mlx_load_png("textures/texture2.png");
	else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
		data->tex.no = mlx_load_png("textures/texture3.png");
	else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.no = mlx_load_png("textures/texture4.png");
	else
		errorr("Error no valid textures path");
	data->map.no += 1;
}

void	wall_texture_so(t_data *data, char *str)
{
	if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
	data->tex.so = mlx_load_png("textures/texture1.png");
	else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
		data->tex.so = mlx_load_png("textures/texture2.png");
	else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
		data->tex.so = mlx_load_png("textures/texture3.png");
	else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.so = mlx_load_png("textures/texture4.png");
	else
		errorr("Error no valid textures path");
	data->map.so += 1;
}

void	wall_texture_we(t_data *data, char *str)
{
	if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture1.png");
	else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture2.png");
	else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture3.png");
	else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture4.png");
	else
		errorr("Error no valid textures path");
	data->map.we += 1;
}

void	wall_texture_ea(t_data *data, char *str)
{
	if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture1.png");
	else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture2.png");
	else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture3.png");
	else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture4.png");
	else
		errorr("Error no valid textures path");
	data->map.ea += 1;
}
