/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/12 16:40:06 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <X11/keysymdef.h> // utiliser les vrais codes car ca peut varier selon os

#define WIDTH 1280
#define HEIGHT 1280
#define STEP 128
#define FONT "-schumacher-*-bold-*-*-*-*-160-*-*-*-*-*-*"

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

/* player turle 
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
*/

/* player sea horse rider */
#define P_WIDTH 128
#define P_HEIGHT 128
#define	P_L_1 "assets/player_seahorse/player_floor_L1_128.xpm"
#define	P_L_2 "assets/player_seahorse/player_floor_L2_128.xpm"
#define	P_L_3 "assets/player_seahorse/player_floor_L3_128.xpm"
#define	P_L_4 "assets/player_seahorse/player_floor_L4_128.xpm"
#define	P_R_1 "assets/player_seahorse/player_floor_R1_128.xpm"
#define	P_R_2 "assets/player_seahorse/player_floor_R2_128.xpm"
#define	P_R_3 "assets/player_seahorse/player_floor_R3_128.xpm"
#define	P_R_4 "assets/player_seahorse/player_floor_R4_128.xpm"
#define	P_U_1 "assets/player_seahorse/player_floor_U1_128.xpm"
#define	P_U_2 "assets/player_seahorse/player_floor_U2_128.xpm"
#define	P_U_3 "assets/player_seahorse/player_floor_U3_128.xpm"
#define	P_U_4 "assets/player_seahorse/player_floor_U4_128.xpm"
#define	P_D_1 "assets/player_seahorse/player_floor_D1_128.xpm"
#define	P_D_2 "assets/player_seahorse/player_floor_D2_128.xpm"
#define	P_D_3 "assets/player_seahorse/player_floor_D3_128.xpm"
#define	P_D_4 "assets/player_seahorse/player_floor_D4_128.xpm"

/* tile */
#define T_WIDTH 128
#define T_HEIGHT 128
/* for turltle set 
#define	GRASS_P "assets/grass.xpm"
#define	WALL_P "assets/white_wall.xpm"
*/
#define	WFLOOR "assets/waterfloor128.xpm"
#define	WWALL "assets/waterwall128.xpm" 


#define	COLLECT_0 "assets/schrimp/schrimp_collect_0_128.xpm"
#define	COLLECT_1 "assets/schrimp/schrimp_collect_1_128.xpm"
#define	COLLECT_2 "assets/schrimp/schrimp_collect_2_128.xpm"
#define	COLLECT_3 "assets/schrimp/schrimp_collect_3_128.xpm"


#define	EXIT_P "assets/exit/exit.xpm"
#define	EXIT_OPEN_P "assets/exit/exit_open.xpm"
#define DOOR_0 "assets/exit/door_0_wfloor_128.xpm"
#define DOOR_25 "assets/exit/door_25_wfloor_128.xpm"
#define DOOR_75 "assets/exit/door_75_wfloor_128.xpm"
#define DOOR_100 "assets/exit/door_100_wfloor_128.xpm"


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
	t_data	*wfloor;
	t_data	*wwall;
	t_data	*collect[4];
	t_data	*exit[4];
}				t_tileset;

typedef struct	s_player
{
	int		x;
	int		y;
	char	dir;
	int		moves;
	int		static_moves;
	int		static_delay;
	int		is_static;
	int		points;
	t_data	*pos_left[4];
	t_data	*pos_right[4];
	t_data	*pos_up[4];
	t_data	*pos_down[4];
}				t_player;

typedef struct	s_vars
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			map_w;
	int			map_h;
	int			c;
	int			c_anim;
	t_rect		*rect;
	t_data		*bg;
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
int		update(t_vars *vars);
int		k_inputs(int keycode, t_vars *vars);
int		m_inputs(int button, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);
void	draw_rects(t_vars *vars);
void	print_rects(t_vars *vars);
void    rect_addback(t_rect *rect, t_vars *vars);
int		load_tileset(t_vars *vars);
void	unload_tileset(t_vars *vars);
t_data	*init_tile(t_vars *vars, char *path);
int		redraw(t_vars *vars);
void	draw_floor_wall(t_vars *vars);
void	draw_collect_door(t_vars *vars);
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
int		player_collect(t_vars *vars);
int		player_wall(t_vars *vars, int y_offset, int x_offset);
int		player_exit(t_vars *vars);
int		player_abt_to_exit(t_vars *vars);
void	free_map(t_vars *vars);
void	draw_score(t_vars *vars);
#endif
