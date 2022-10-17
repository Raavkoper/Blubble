/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:45 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/17 14:27:42 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_floor(t_data *data, char *line)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	b = ft_atoi(line);
	data->f_color = create_rgba(r, g, b, 255);
	data->map.f += 1;
}

void	color_ceiling(t_data *data, char *line)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	b = ft_atoi(line);
	data->c_color = create_rgba(r, g, b, 255);
	data->map.c += 1;
}

void	draw_f_c(t_data *data, uint32_t	color, char c)
{
	int			x;
	int			y;
	int			end;

	if (c == 'c')
		y = 0;
	else
		y = SCREENHEIGHT / 2;
	end = y + (SCREENHEIGHT / 2);
	while (y < end)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			mlx_put_pixel(data->g_img, x, y, color);
			x++;
		}
		y++;
	}
}

void	check_floor_ceiling(t_data *data, char *line)
{
	if (line[0] == 'F')
		color_floor(data, line);
	else if (line[0] == 'C')
		color_ceiling(data, line);
	else
		errorr("Error you didn't specify the color");
}
