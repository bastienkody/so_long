/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/16 16:10:27 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <X11/keysymdef.h> // utiliser les vrais codes car ca peut varier selon os ?

/* main stuff */
#define STEP 128
#define FONT "-schumacher-*-bold-*-*-*-*-160-*-*-*-*-*-*"
#define SHARK_TIMER_MAC 55
#define SHARK_TIMER_UBU 7000
#define PLAY_S_DELAY_MAC 55
#define PLAY_S_DELAY_UBU 5500
#define C_ANIM_MAC 400
#define C_STEP_MAC 100
#define C_ANIM_UBU 40000
#define C_STEP_UBU 10000

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
// floor for turtle player 
#define	GRASS_P "assets/grass.xpm"
#define	WALL_P "assets/white_wall.xpm"
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
#define	POS_SR_4 "assets/player/static_right_4_bg.xpm" */

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

/* shark enemy */
#define	S_L_1 "assets/shark/shark_l_1_128.xpm"
#define	S_L_2 "assets/shark/shark_l_2_128.xpm"
#define	S_L_3 "assets/shark/shark_l_3_128.xpm"
#define	S_L_4 "assets/shark/shark_l_4_128.xpm"
#define	S_R_1 "assets/shark/shark_r_1_128.xpm"
#define	S_R_2 "assets/shark/shark_r_2_128.xpm"
#define	S_R_3 "assets/shark/shark_r_3_128.xpm"
#define	S_R_4 "assets/shark/shark_r_4_128.xpm"
#define	S_U_1 "assets/shark/shark_u_1_128.xpm"
#define	S_U_2 "assets/shark/shark_u_2_128.xpm"
#define	S_U_3 "assets/shark/shark_u_3_128.xpm"
#define	S_U_4 "assets/shark/shark_u_4_128.xpm"
#define	S_D_1 "assets/shark/shark_d_1_128.xpm"
#define	S_D_2 "assets/shark/shark_d_2_128.xpm"
#define	S_D_3 "assets/shark/shark_d_3_128.xpm"
#define	S_D_4 "assets/shark/shark_d_4_128.xpm"

/* tile */
#define T_WIDTH 128
#define T_HEIGHT 128
#define	WWALL "assets/waterwall_green128.xpm" 
#define	WFLOOR "assets/waterfloor128.xpm"
#define DOOR_0 "assets/exit/door_0_wfloor_128.xpm"
#define DOOR_25 "assets/exit/door_25_wfloor_128.xpm"
#define DOOR_75 "assets/exit/door_75_wfloor_128.xpm"
#define DOOR_100 "assets/exit/door_100_wfloor_128.xpm"

/* schrimp collectibles */
#define	COLLECT_0 "assets/schrimp/schrimp_collect_0_128.xpm"
#define	COLLECT_1 "assets/schrimp/schrimp_collect_1_128.xpm"
#define	COLLECT_2 "assets/schrimp/schrimp_collect_2_128.xpm"
#define	COLLECT_3 "assets/schrimp/schrimp_collect_3_128.xpm"

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
	t_data	*pos_l[4];
	t_data	*pos_r[4];
	t_data	*pos_u[4];
	t_data	*pos_d[4];
}				t_player;

typedef struct	s_shark
{
	int		x;
	int		y;
	char	dir;
	int		moves;
	int		delay;
	int		is_alive;
	t_data	*pos_l[4];
	t_data	*pos_r[4];
	t_data	*pos_u[4];
	t_data	*pos_d[4];
}				t_shark;

typedef struct	s_v
{
	void		*ptr;
	void		*win;
	char		**map;
	int			map_w;
	int			map_h;
	int			ini_c;
	int			current_c;
	int			c_anim;
	int			nb_enemies;
	t_tileset	*tileset;
	t_player	*player;
	t_shark		**shark;
}				t_v;

/* prototypes */
void		pix_to_img(t_data *img, int x, int y, int color);
int			resize_rect(int keycode, t_v *v);
int			update(t_v *v);
int			k_inputs(int keycode, t_v *v);
int			m_inputs(int button, int x, int y, t_v *v);
int			close_window(t_v *v);
int			load_tileset(t_v *v);
void		unload_tileset(t_v *v);
t_data		*init_tile(t_v *v, char *path);
int			redraw(t_v *v);
void		draw_floor_wall(t_v *v);
int			load_player(t_v *v);
void		unload_player(t_v *v);
t_data		*init_sprite(t_v *v, char *path);
void		move_player(int keycode, t_v *v);
void		draw_player(t_v *v);
int			map_error(char *msg);
int			arg_error(int argc, char **argv);
char		**get_map(char *map_path);
int			check_map(char **map, t_v *v);
int			check_char(char *line);
int			check_wall(t_v *v);
int			check_c(t_v *v);
int			check_p(t_v *v);
int			check_e(t_v *v);
void		print_map(char **map);
void		get_player_ini_pos(t_v *v);
int			player_collect(t_v *v);
int			player_wall(t_v *v, int y_oset, int x_oset);
int			player_exit(t_v *v);
void		free_map(t_v *v, char **map);
void		draw_score(t_v *v);
void		draw_door(t_v *v);
void		draw_collect(t_v *v);
t_shark		*load_shark(t_v *v);
int			get_enemies_from_map(t_v *v);
void		print_shark(t_v *v);
int			init_sharks(t_v *v);
void		draw_shark(t_v *v, int i);
void		unload_shark(t_v *v, int nb);
int			shark_can_move(t_v *v, int i, int y_oset, int x_oset);
int			move_shark(t_v *v, int i);
int			shark_player(t_v *v);
int			backtrack_player(t_v *v, char *path);
int			backtrack_collect(t_v *v, char *path);
#endif
