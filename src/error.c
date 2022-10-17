/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:03:38 by rkoper            #+#    #+#             */
/*   Updated: 2022/10/17 14:59:40 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	errorr(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

void	cub_extension_check(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (map_file[len - 4] != '.' || map_file[len - 3] != 'c' \
		|| map_file[len - 2] != 'u' || map_file[len - 1] != 'b')
		errorr("Error failed to use a map with a .cub extension :(");
}

void	check_closed_walls2(t_map map, int i, int j)
{
	if (!i || i == map.height - 1)
	{
		if (map.map[i][j] != ' ' && map.map[i][j] \
		!= '1' && map.map[i][j] != '\n')
			errorr("Error open spaces left on map :/");
	}
	else
	{
		if (map.map[i][j] == '0')
		{
			if ((map.map[i][j + 1] != '0' && map.map[i][j + 1] != '1') \
			|| (map.map[i][j - 1] != '0' && map.map[i][j - 1] != '1') \
			|| (map.map[i + 1][j] != '0' && map.map[i + 1][j] != '1') \
			|| (map.map[i - 1][j] != '0' && map.map[i - 1][j] != '1'))
				errorr("Error open spaces left on map :/");
		}
	}
}

void	check_closed_walls(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map.height)
	{
		j = 0;
		while (map.map[i][j])
		{
			check_closed_walls2(map, i, j);
			j++;
		}
		i++;
	}
}
