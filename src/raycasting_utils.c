/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 12:03:24 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/09/29 14:53:05 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	calculate_step_direction(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->cam.posx - data->ray.mapx) \
		* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->cam.posx) \
		* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->cam.posy - data->ray.mapy) \
		* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->cam.posy) \
		* data->ray.deltadisty;
	}
}

void	check_for_wall_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map.map[data->ray.mapy][data->ray.mapx] > '0')
			data->ray.hit = 1;
	}
}

void	calculate_perpwalldist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltadistx;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltadisty;
	data->ray.lineheight = (int)(data->mlx->height / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + data->mlx->height / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + data->mlx->height / 2;
	if (data->ray.drawend >= data->mlx->height)
		data->ray.drawend = data->mlx->height - 1;
	// data->ray.texnum = data->map.map[data->ray.mapx][data->ray.mapy] - 1;
}

void	calculate_textures(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wallx = data->cam.posy + \
		data->ray.perpwalldist * data->ray.raydiry;
	else
		data->ray.wallx = data->cam.posx + \
		data->ray.perpwalldist * data->ray.raydirx;
	data->ray.texx = (int)(data->ray.wallx * (double)TEXWIDTH);
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		data->ray.texx = TEXWIDTH - data->ray.texx - 1;
	if (data->ray.side == 1 && data->ray.raydiry > 0)
		data->ray.texx = TEXWIDTH - data->ray.texx - 1;
	data->ray.step = 1.0 * TEXHEIGHT / data->ray.lineheight;
	data->ray.texpos = (data->ray.drawstart - \
	data->mlx->height / 2 + data->ray.lineheight / 2) * data->ray.step;
	printf("2  %d\n", data->ray.texx);
}

void	draw_walls(t_data *data, int x)
{
	double			step;
	double			texpos;
	int				texy;
	int				y;
	uint32_t		color;
	
	step = 1.0 * data->xpm.texture.height / data->ray.lineheight;
	texpos = (data->ray.drawstart - data->mlx->height / 2 + data->ray.lineheight / 2) * step;
	y = data->ray.drawstart;
	while (y < data->ray.drawend && y < data->mlx->height)
	{
		texy = (int)texpos % (data->xpm.texture.height) - 1;
		texpos += step;
		// color = 0;
		// printf("texwidh: %d\n", data->xpm.texture.width);
		if (data->ray.texx >= 0)
			color = (*(uint32_t *)(data->xpm.texture.pixels + (data->xpm.texture.width * texy + data->ray.texx) * 4));
		*(uint32_t *)(data->g_img->pixels + ((y * data->g_img->width + x) * 4)) = color;
		y++;
	}
}
