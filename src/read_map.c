/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:39:59 by rkoper        #+#    #+#                 */
/*   Updated: 2022/08/29 11:15:53 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	read_map(t_data *data, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	init_map(data, fd);
}

void	append_map(char content, int x, int y, t_data *data)
{
	t_map	*new_node;
	t_map	*last;

	last = data->map;
	new_node = malloc(sizeof(t_map));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->x = x;
	new_node->y = y;
	new_node->content = content;
	new_node->next = NULL;
	if (!data->map)
	{
		data->map = new_node;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	init_map(t_data *data, int fd)
{
	char *line;
	char *temp;
	int x;
	int y;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		temp = line;
		while (*line && *line != '\n')
		{
			append_map(*line, x, y, data);
			line++;
			x += 1;
		}
		free(temp);
		line = get_next_line(fd);
		y += 1;
	}
}

void	print_map(t_map *map)
{
	while (map)
	{
		printf("x = %d, y = %d, content = %c\n", map->x, map->y, map->content);
		map = map->next;
	}
}