/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:31:58 by rkoper            #+#    #+#             */
/*   Updated: 2022/08/02 11:12:32 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/blubble.h"

int	main(void)
{
	t_data	data;

	init_game(&data);
	create_window(&data);
	read_map(&data);
	mlx_loop(data.mlx);
}
