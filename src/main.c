/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 10:31:58 by rkoper        #+#    #+#                 */
/*   Updated: 2022/08/02 13:56:13 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	main(void)
{
	t_data	data;

	init_game(&data);
	create_window(&data);
	read_map(&data);
	printf("%d\n", ft_strlen("poep\n"));
	mlx_loop(data.mlx);
}
