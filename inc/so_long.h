/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/11 14:41:43 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define WIDTH 1280
#define HEIGHT 1280
#define STEP 128
#define FONT "-schumacher-*-bold-*-normal-*-8-*-75-75-*-*-*-*"

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
#define	POS_L_1 "assets/player/player_left_1_bg.xpm"
#define	POS_L_2 "assets/player/player_left_2_bg.xpm"
#define	POS_L_3 "assets/player/player_left_3_bg.xpm"
#define	POS_L_4 "assets/player/player_left_4_bg.xpm"
#define	POS_R_1 "assets/player/player_right_1_bg.xpm"
#define	POS_R_2 "assets/player/player_right_2_bg.xpm"
#define	POS_R_3 "assets/player/player_right_3_bg.xpm"
#define	POS_R_4 "assets/player/player_right_4_bg.xpm"
#define	POS_SL_1 "assets/player/static_left_1_bg.xpm"
#define	POS_SL_2 "assets/player/static_left_2_bg.xpm"
#define	POS_SL_3 "assets/player/static_left_3_bg.xpm"
#define	POS_SL_4 "assets/player/static_left_4_bg.xpm"
#define	POS_SR_1 "assets/player/static_right_1_bg.xpm"
#define	POS_SR_2 "assets/player/static_right_2_bg.xpm"
#define	POS_SR_3 "assets/player/static_right_3_bg.xpm"
#define	POS_SR_4 "assets/player/static_right_4_bg.xpm"

/* tile */
#define T_WIDTH 128
#define T_HEIGHT 128
#define	GRASS_P "assets/grass.xpm"
#define	WALL_P "assets/white_wall.xpm"
#define	COLLECT_P "assets/collect_bg.xpm"
#define	EXIT_P "assets/exit/exit.xpm"
#define	EXIT_OPEN_P "assets/exit/exit_open.xpm"


/* struct */
typedef struct	s_rect
{
	int x;
	int y;
	int width;
	int height;
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
	t_data	*exit[2];
}				t_tileset;

typedef struct	s_player
{
	int		x;
	int		y;
	char	dir;
	int		moves;
	int		l_moves;
	int		r_moves;
	int		static_moves;
	int		static_delay;
	int		is_static;
	int		points;
	t_data	*pos_left[3];
	t_data	*pos_right[3];
	t_data	*pos_static_l[4];
	t_data	*pos_static_r[4];
}				t_player;

typedef struct	s_vars
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			map_w;
	int			map_h;
	t_rect		*rect;
	t_data		*img;
	t_tileset	*tileset;
	t_player	*player;
}				t_vars;

/* prototypes */
void	pix_to_img(t_data *img, int x, int y, int color);
void	bg_pix_to_img(t_data *img, int color);
void	rect_pix_to_img(t_data *img, t_rect *rect, int color);
t_rect	*init_t_rect(int x, int y, int width, int height);
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
int		arg_error(int argc, char **argv);
char	**get_map(char *map_path);
int		check_map(char **map, t_vars *vars);
int		check_wall(char **map, int nb_line, int line_len);
void	print_map(char **map);
void	get_player_ini_pos(t_vars *vars);
void	player_collect(t_vars *vars);
int		player_wall(t_vars *vars, int y_offset, int x_offset);
int		player_exit(t_vars *vars);
int		player_abt_to_exit(t_vars *vars);
#endif
