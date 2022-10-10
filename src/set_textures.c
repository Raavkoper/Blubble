/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:49 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/06 15:44:38 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	wall_texture_no_so(t_data *data, char c, char *str)
{
	if (c == 'N')
	{
		if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
			data->tex.no = mlx_load_png("textures/texture1.png");
		else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
			data->tex.no = mlx_load_png("textures/texture2.png");
		else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
			data->tex.no = mlx_load_png("textures/texture3.png");
		else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
			data->tex.no = mlx_load_png("textures/texture4.png");
	}
	else if (c == 'S')
	{
		if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.so = mlx_load_png("textures/texture1.png");
		else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
			data->tex.so = mlx_load_png("textures/texture2.png");
		else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
			data->tex.so = mlx_load_png("textures/texture3.png");
		else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.so = mlx_load_png("textures/texture4.png");
	}
}

void	wall_texture_we_ea(t_data *data, char c, char *str)
{
	if (c == 'W')
	{
		if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture1.png");
		else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
			data->tex.we = mlx_load_png("textures/texture2.png");
		else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
			data->tex.we = mlx_load_png("textures/texture3.png");
		else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.we = mlx_load_png("textures/texture4.png");
	}
	else if (c == 'E')
	{
		if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture1.png");
		else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
			data->tex.ea = mlx_load_png("textures/texture2.png");
		else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
			data->tex.ea = mlx_load_png("textures/texture3.png");
		else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.ea = mlx_load_png("textures/texture4.png");
	}
}

void	safe_wall_textures(t_data *data, char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 5;
	str = ft_calloc(strlen(line) + 1, 1);
	while (line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}
	i = 0;
	if (line[i] == 'N')
		wall_texture_no_so(data, line[i], str);
	else if (line[i] == 'S')
		wall_texture_no_so(data, line[i], str);
	else if (line[i] == 'W')
		wall_texture_we_ea(data, line[i], str);
	else if (line[i] == 'E')
		wall_texture_we_ea(data, line[i], str);
	free(str);
	j++;
}

void	set_textures(t_data *data, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (i < 4)
	{
		safe_wall_textures(data, line);
		temp = line;
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	if (line[0] != '\n' || !line[0])
		errorr("Error whitespace error\n");
	free(line);
}
