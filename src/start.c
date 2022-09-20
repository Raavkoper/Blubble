/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:02:41 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/20 13:31:12 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	start(void *param)
{	
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	data->cam.rotspeed = 0.05;
	key_input(data);
	draw_f_c(data, data->c_color, 'c');
	draw_f_c(data, data->f_color, 'f');
	raycasting(data);
}
