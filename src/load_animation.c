/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:54:22 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/14 15:46:59 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

mlx_texture_t	*load_fish(t_data *data)
{
	static int	i = 0;
	int			x;

	x = 5000;
	if (i == 0)
		data->tex.no = data->tex.fish[12];
	if (i == x)
		data->tex.no = data->tex.fish[11];
	if (i == x * 2)
		data->tex.no = data->tex.fish[10];
	if (i == x * 3)
		data->tex.no = data->tex.fish[9];
	if (i == x * 4)
		data->tex.no = data->tex.fish[8];
	if (i == x * 5)
		data->tex.no = data->tex.fish[7];
	if (i == x * 6)
		data->tex.no = data->tex.fish[6];
	if (i == x * 7)
		data->tex.no = data->tex.fish[5];
	if (i == x * 8)
		data->tex.no = data->tex.fish[4];
	if (i == x * 9)
		data->tex.no = data->tex.fish[3];
	if (i == x * 10)
		data->tex.no = data->tex.fish[2];
	if (i == x * 11)
		data->tex.no = data->tex.fish[1];
	if (i == x * 12)
		data->tex.no = data->tex.fish[0];
	if (i == x * 13)
		i = 0;
	i++;
	return (data->tex.no);
}
