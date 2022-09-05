/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:17:44 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/05 13:55:48 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	raycasting(t_data *data)
{
	double posX = 14;
	double posY = 8;
	double dirX	= -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	double time = 0;
	double oldtime = 0;
	int x = 0;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int	mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	unsigned int color;
	int texNum;
	double wallX;
	int texX;
	int texY;
	double texPos;
	double step;
	int y;
	hit = 0;
	
	while (x < data->mlx->width)
	{
		cameraX = 2 * x / screenWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		hit = 0;
		if (!rayDirX)
			rayDirX = 1e30;
		else
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		if (!rayDirY)
			rayDirY = 1e30;
		else
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (!side)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		lineHeight = (int)(data->mlx->height / perpWallDist);
		drawStart = -lineHeight / 2 + data->mlx->height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + data->mlx->height / 2;
		if (drawEnd >= data->mlx->height)
			drawEnd = data->mlx->height - 1;
		// texNum = worldMap[mapX, mapY];
		// printf("lineheight%d\n", lineHeight);
		if (worldMap[mapX][mapY] == 1)
		{
			color = create_rgba(6, 57, 112, 255);
			printf("hoi\n");
			if (side)
				color = create_rgba(7, 68, 125, 255);
		}
		if (worldMap[mapX][mapY] == 2)
		{
			color = create_rgba(227, 116, 60, 255);
			printf("hoi\n");
			if (side)
				color = create_rgba(209, 100, 43, 255);
		}
		if (worldMap[mapX][mapY] == 3)
		{
			color = create_rgba(204, 206, 204, 255);
			printf("hoi\n");
			if (side)
				color = create_rgba(78, 179, 242, 255);
		}
		if (worldMap[mapX][mapY] == 4)
		{
			color = create_rgba(198, 132, 96, 255);
			printf("hoi\n");
			if (side)
				color = create_rgba(155, 51, 25, 255);
		}
		if (!side)
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		texX = (int)wallX * (double)texWidth;
		if (!side && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		step = 1.0 * texHeight / lineHeight;
		texPos = (drawStart - data->mlx->height / 2 + lineHeight / 2) * step;
		y = drawStart;
		while (y < drawEnd && y < data->mlx->height)
		{
			texY = (int)texPos & (texHeight - 1);
			texPos += step;
			mlx_put_pixel(data->g_img, x, y, color);
			y++;
		}
		// draw_walls(data, x, drawStart, drawEnd);
		x++;
	}
}


void	draw_ceiling(t_data *data)
{
	int			x;
	int			y;
	uint32_t	color = create_rgba(78, 179, 242, 255);
	
	y = 0;
	while (y < screenHeight / 2)
	{
		x = 0;
		while (x < screenWidth)
		{
			mlx_put_pixel(data->g_img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *data)
{
	int			x;
	int			y;
	uint32_t	color = create_rgba(3, 90, 252, 255);
	
	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			mlx_put_pixel(data->g_img, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_walls(t_data *data, int x, int drawStart, int drawEnd)
{
	while (drawStart != drawEnd)
	{
		mlx_put_pixel(data->g_img, x, drawStart, 255);
		if (drawStart > drawEnd)
			drawStart--;
		else
			drawStart++;
	}
}
