/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:17:44 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/02 13:47:39 by rkoper        ########   odam.nl         */
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

void	raycasting(t_data *data)
{
	double posX = 22;
	double posY = 12;
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
	int hit = 0;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	unsigned int color;
	
	while (x < mapWidth)
	{
		cameraX = 2 * x / mapWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirX + planeX * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		if (!rayDirX)
			rayDirX = 1e30;
		else
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		if (!rayDirY)
			rayDirY = 1e30;
		else
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		x++;
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
			perpWallDist = sideDistX - deltaDistY;
		else
			perpWallDist = sideDistY - deltaDistY;
		lineHeight = (int)(mapHeight / perpWallDist);
		drawStart = -lineHeight / 2 + mapHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + mapHeight / 2;
		if (drawEnd >= mapHeight)
			drawEnd = mapHeight - 1;
		if (worldMap[mapX][mapY] == 1)
		{
			color = 0xFF0000;
			if (side)
				color = 0xAC1111;
		}
		if (worldMap[mapX][mapY] == 2)
		{
			color = 0xFFF600;
			if (side)
				color = 0xCBC706;
		}
		if (worldMap[mapX][mapY] == 3)
		{
			color = 0x0007FF;
			if (side)
				color = 0x0B86AD;
		}
		if (worldMap[mapX][mapY] == 4)
		{
			color = 0x03FF00;
			if (side)
				color = 0x1BA01A;
		}
		draw_walls(data, x, drawStart, drawEnd);
	}
}

int	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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
	int	y;
	
	y = drawStart;
	while (y < drawEnd)
	{
		
	}
}
