/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blubble.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-ass <svan-ass@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 11:13:37 by svan-ass      #+#    #+#                 */
/*   Updated: 2022/09/19 12:48:50 by rkoper        ########   odam.nl         */
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
# include <time.h>

# include "../libs/mlx/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

# define mapWidth 24
# define mapHeight 24
# define texWidth 64
# define texHeight 64
# define screenWidth 640
# define screenHeight 480

typedef struct s_player {
	double	movespeed;
}				t_player;

typedef struct s_camera {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	rotspeed;
}				t_camera;

typedef struct s_raycasting {
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	step;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		drawstart;
	int		drawend;
	int		lineheight;
	double	wallx;
	int		texx;
	int		texy;
	double	texpos;
}				t_raycasting;

typedef struct s_map {
	char	**map;
	int		width;
	int 	height;
}				t_map;

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_map			*map;
	t_raycasting	ray;
	t_player		player;
	t_camera		cam;
}				t_data;

//main
int		worldMap[mapWidth][mapHeight];
void	init_game(t_data *data);
void	create_window(t_data *data);

//init data
void	init_raycasting(t_data *data, int x);
void	init_camera(t_data *data);

//raycasting
void	hook(void *param);
void	raycasting(t_data *data);
void	calculate_step_direction(t_data *data);
void	check_for_wall_hit(t_data *data);
void	calculate_perpwalldist(t_data *data);
void	calculate_textures(t_data *data);
void	draw_walls(t_data *data, int x, int color);

int		wall_colors(t_data *data);

//keys
void	key_input(t_data *data);

/* map parse functions */
void	read_map(t_data *data);
void	init_map(t_data *data, int fd);
void	set_textures(t_data *data, int fd);
void	color_map(t_data *data, int fd);
void	copy_map(t_map *map, int fd);

void	draw_f_c(t_data *data, uint32_t	color, char c);
int		create_rgba(int r, int g, int b, int a);
#endif
