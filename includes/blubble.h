/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blubble.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:13:37 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/08/03 13:20:18 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLUBBLE_H
# define BLUBBLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>

# include "../libs/mlx/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

typedef struct s_map {
	char			content;
	int				x;
	int				y;
	struct s_map	*next;
}				t_map;

typedef struct s_data {
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_map		*map;
}	t_data;

void	read_map(t_data *data);
void	init_game(t_data *data);
void	create_window(t_data *data);

#endif
