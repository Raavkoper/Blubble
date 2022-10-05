/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:07:49 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/05 15:09:57 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	safe_wall_textures(t_data *data, char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 5;
	str = ft_calloc(strlen(line) + 1, 1);
	while (line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}
	if (ft_strncmp(str, "textures/texture1.png", 21) == 0)
		data->tex.tex1 = mlx_load_png("textures/texture1.png");
	else if (ft_strncmp(str, "textures/texture2.png", 21) == 0)
		data->tex.tex2 = mlx_load_png("textures/texture2.png");
	else if (ft_strncmp(str, "textures/texture3.png", 21) == 0)
		data->tex.tex3 = mlx_load_png("textures/texture3.png");
	else if (ft_strncmp(str, "textures/texture4.png", 21) == 0)
		data->tex.tex4 = mlx_load_png("textures/texture4.png");
	free(str);
	j++;
}