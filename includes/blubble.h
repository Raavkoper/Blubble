/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blubble.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:13:37 by svan-ass          #+#    #+#             */
/*   Updated: 2022/10/11 11:50:33 by svan-ass         ###   ########.fr       */
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

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define SCREENWIDTH 640
# define SCREENHEIGHT 480

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
	int		texnum;
	double	texpos;
}				t_raycasting;

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}				t_map;

typedef struct s_textures {
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}				t_textures;

typedef struct s_data {
	char			*map_file;
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	mlx_image_t		*img;
	t_map			map;
	t_raycasting	ray;
	t_player		player;
	t_camera		cam;
	t_textures		tex;
	int				i;
	int				c_color;
	int				f_color;
	int				start_map_line;
}				t_data;

/* main */
void	init_game(t_data *data);
void	init_data(t_data *data);
void	create_window(t_data *data);

/* init data */
void	init_raycasting(t_data *data, int x);
void	init_camera(t_data *data);

/* raycasting */
void	start(void *param);
void	raycasting(t_data *data);
void	calculate_step_direction(t_data *data);
void	check_for_wall_hit(t_data *data);
void	calculate_perpwalldist(t_data *data);
void	calculate_textures(t_data *data);
void	draw_walls(t_data *data, int x, mlx_texture_t *texture);

/* textures */
int		safe_wall_textures(t_data *data, char *line);
void	set_textures(t_data *data, int fd);
void	wall_texture_no(t_data *data, char *str);
void	wall_texture_so(t_data *data, char *str);
void	wall_texture_we(t_data *data, char *str);
void	wall_texture_ea(t_data *data, char *str);
void	double_check_map(t_data *data);

/* color */
void	check_floor_ceiling(t_data *data, char *line, int fd);
void	elements(t_data *data, int fd, int line_count);
void	color_floor(t_data *data, char *line);
void	color_ceiling(t_data *data, char *line);
int		wall_colors(t_data *data);
void	draw_f_c(t_data *data, uint32_t	color, char c);
int		create_rgba(int r, int g, int b, int a);

/* keys */
void	key_input(t_data *data);
void	input_data_up(t_data *data);
void	input_data_down(t_data *data);
void	input_data_left(t_data *data);
void	input_data_right(t_data *data);

/* map parsing */
void	read_map(t_data *data);
void	init_map(t_data *data, int fd);
void	set_textures(t_data *data, int fd);
void	color_map(t_data *data, int fd);
int		check_player_direction(t_data *data, char *line, int j);
int		map_strlen(char const *str);

/* error checking */
void	errorr(char *s);
void	cub_extension_check(char *map_file);
void	check_closed_walls(t_map map);

#endif
