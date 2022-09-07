/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blubble.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:13:37 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/09/07 14:11:15 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLUBBLE_H
# define BLUBBLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>

# include "../libs/mlx/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

# define mapWidth 24
# define mapHeight 24
# define texWidth 64
# define texHeight 64
# define screenWidth 640
# define screenHeight 480

typedef struct s_map {
	char	**map;
	int		width;
	int 	height;
}				t_map;

typedef struct s_data {
	char		*file;
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_map		map;
}	t_data;

/* map parse functions */
void	read_map(t_data *data);
void	init_map(t_data *data, int fd);
void	set_textures(t_data *data, int fd);
void	color_map(t_data *data, int fd);
void	copy_map(t_map *map, int fd);

void	init_game(t_data *data);
void	create_window(t_data *data);
void	raycasting(t_data *data);
void	draw_f_c(t_data *data, uint32_t	color, char c);
int		create_rgba(int r, int g, int b, int a);
#endif
