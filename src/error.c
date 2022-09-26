/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 10:03:38 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/26 11:29:10 by rkoper        ########   odam.nl         */
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

void	error_map(t_data *data, int fd)
{
	if (fd == -1 || fd > OPEN_MAX)
	{
		printf("Error opening map file\n");
		exit(1);
	}
	cub_extension_check(data->map_file);
	
}