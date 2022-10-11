/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:49 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/11 11:55:07 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	double_check_map(t_data *data)
{
	if (data->map.no != 1 || data->map.so != 1 \
	|| data->map.we != 1 || data->map.ea != 1 \
	|| data->map.f != 1 || data->map.c != 1)
		errorr("Error no right texture identifier");
}

char	*str_cpy(char *str, char *line)
{
	int	j;
	int	i;

	j = 0;
	i = 2;
	while (line[i] == ' ' || line[i] == '.' || line[i] == '/')
		i++;
	while (line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}	
	return (str);
}

int	safe_wall_textures(t_data *data, char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 2;
	str = ft_calloc(strlen(line) + 1, 1);
	str = str_cpy(str, line);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		wall_texture_no(data, str);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		wall_texture_so(data, str);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		wall_texture_we(data, str);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		wall_texture_ea(data, str);
	else
		errorr("Error no right texture identifier");
	free(str);
	return (1);
}
