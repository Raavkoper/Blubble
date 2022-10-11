/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:05:19 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/11 13:11:46 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	check_width_height(t_map *map, int fd, char *line)
{
	int	height;
	int	width;
	int	max;

	height = 0;
	max = 0;
	while (line)
	{
		width = map_strlen(line);
		if (width > max)
			max = width;
		free(line);
		line = get_next_line(fd);
		height++;
	}
	map->width = max;
	map->height = height;
}
