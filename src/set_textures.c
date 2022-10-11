/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:49 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/10 15:33:59 by svan-ass         ###   ########.fr       */
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
}

int	safe_wall_textures(t_data *data, char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 2;
	str = ft_calloc(strlen(line) + 1, 1);
	while (line[i] == ' ' || line[i] == '.' || line[i] == '/')
		i++;
	while (line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		wall_texture_no(data, str);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		wall_texture_so(data, str);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		wall_texture_we(data, str);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		wall_texture_ea(data, str);
	else
		errorr("Error no right texture identifier");
	free(str);
	return (1);
}
