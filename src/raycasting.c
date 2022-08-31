/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:17:44 by rkoper        #+#    #+#                 */
/*   Updated: 2022/08/31 13:20:01 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	raycasting()
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
	while (x < mapWidth)
	{
		cameraX = 2 * x / mapWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirX + planeX * cameraX;
		x++;
	}
}