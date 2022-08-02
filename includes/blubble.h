#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../libraries/mlx/mlx.h"
# include "../libraries/libft/libft.h"

typedef struct s_map {
	char			content;
	int				x;
	int 			y;
	struct s_map	*next;
}				t_map;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef	struct s_data {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	image;
}				t_data;

void	read_map(t_data *data);
void	init_game(t_data *data);
void	create_window(t_data *data);

#endif
