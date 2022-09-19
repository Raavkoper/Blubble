/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:02:41 by rkoper        #+#    #+#                 */
/*   Updated: 2022/09/19 13:33:02 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

void	hook(void *param)
{	
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	// printf("left -> posx: %f posy: %f\n", data->cam.dirx, data->cam.diry);
}
