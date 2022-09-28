/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 10:03:38 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/28 15:27:11 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	cub_extension_check(char *map_file)
{
	int len;

	len = ft_strlen(map_file);
	if (map_file[len - 4] != '.' || map_file[len - 3] != 'c' \
		|| map_file[len - 2] != 'u' || map_file[len - 1] != 'b')
	{
		printf("Error failed to use a map with a .cub extension :(\n");
		exit(1);
	}
}

void	check_closed_walls(t_map map)
{
	int i;
	int j;
	
	i = 0;
	while (i <= map.height)
	{
		j = 0;
		while (map.map[i][j])
		{
			if (!i || i == map.height - 1)
			{
				if (map.map[i][j] != ' ' && map.map[i][j] != '1' && map.map[i][j] != '\n')
				{
					printf("Error open spaces left on map x; %d, y; %d\n", j, i);
					exit(1);
				}
			}
			else
			{
				if (map.map[i][j] == '0')
				{
					if ((map.map[i][j + 1] != '0' && map.map[i][j + 1] != '1') \
					||	(map.map[i][j - 1] != '0' && map.map[i][j - 1] != '1') \
					||	(map.map[i + 1][j] != '0' && map.map[i + 1][j] != '1') \
					||	(map.map[i - 1][j] != '0' && map.map[i - 1][j] != '1'))
					{
						printf("Error open spaces left on map x; %d, y; %d\n", j, i);
						exit(1);
					}
				}
			}
			j++;
		}
		i++;	
	}
}