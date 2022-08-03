/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blubble.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:13:37 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/08/02 13:53:00 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLUBBLE_H
# define BLUBBLE_H
# include <stdio.h>
# include <stdlib.h>

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

typedef struct s_map {
	char			content;
	int				x;
	int				y;
	struct s_map	*next;
}				t_map;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	image;
}	t_data;

void	read_map(t_data *data);
void	init_game(t_data *data);
void	create_window(t_data *data);

#endif
