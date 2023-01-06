/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 20:25:43 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define WIDTH 1280
#define HEIGHT 1280
#define STEP 128

/* keycode */
#define W 119
#define A 97
#define S 115
#define D 100
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

/* mouse button */
#define LEFT_C 1
#define RIGHT_C 2
#define SCROLL 3
#define SCROLL_U 4
#define SCROLL_D 5

/* colors */
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000

/* player */
#define P_WIDTH 128
#define P_HEIGHT 128
#define	POS_ONE_P "assets/turtle.xpm"


/* tile */
#define T_WIDTH 128
#define T_HEIGHT 128
#define	GRASS_P "assets/grass.xpm"
#define	WALL_P "assets/white_wall.xpm"


/* struct */
typedef struct	s_rect
{
	int x;
	int y;
	int width;
	int height;
	struct s_rect	*next;
}				t_rect;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_tileset
{
	t_data	*grass;
	t_data	*wall;
	t_data	*collect;
	t_data	*obstacle;
	t_data	*exit;
}				t_tileset;

typedef struct	s_player
{
	int		x;
	int		y;
	t_data	*pos_one;
}				t_player;

typedef struct	s_vars
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	t_rect		*rect;
	t_data		*img;
	t_tileset	*tileset;
	t_player	*player;
	int			moves;
}				t_vars;

/* prototypes */
void	pix_to_img(t_data *img, int x, int y, int color);
void	bg_pix_to_img(t_data *img, int color);
void	rect_pix_to_img(t_data *img, t_rect *rect, int color);
void	init_t_rect(t_rect *rect, int x, int y, int width, int height);
int		move_rect(int keycode, t_vars *vars);
int		resize_rect(int keycode, t_vars *vars);
int		k_inputs(int keycode, t_vars *vars);
int		m_inputs(int button, int x, int y, t_vars *vars);
void	draw_rects(t_vars *vars);
void	print_rects(t_vars *vars);
void    rect_addback(t_rect *rect, t_vars *vars);
int		load_tileset(t_vars *vars);
void	unload_tileset(t_vars *vars);
t_data	*init_tile(t_vars *vars, char *path);
int		redraw(t_vars *vars);
void	draw_floor(t_vars *vars);
void	draw_walls(t_vars *vars);
int		load_player(t_vars *vars);
void	unload_player(t_vars *vars);
t_data	*init_sprite(t_vars *vars, char *path);
void	move_player(int keycode, t_vars *vars);
void    draw_player(t_vars *vars);
int		map_error(char *msg);
int		arg_error(void);
char	**get_map(char *map_path);
int		check_map(char **map);
int		check_wall(char **map, int nb_line, int line_len);
void	print_map(char **map);
#endif
