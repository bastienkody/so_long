/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/23 15:37:31 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/keysym.h>

/* main stuff */
# define STEP 128

/* player sea horse rider */
# define P_WIDTH 128
# define P_HEIGHT 128
# define P_L "assets/player_seahorse/player_floor_L1_128.xpm"
# define P_R "assets/player_seahorse/player_floor_R1_128.xpm"
# define P_U "assets/player_seahorse/player_floor_U1_128.xpm"
# define P_D "assets/player_seahorse/player_floor_D1_128.xpm"

/* tile */
# define T_WIDTH 128
# define T_HEIGHT 128
# define WWALL "assets/waterwall_green128.xpm" 
# define WFLOOR "assets/waterfloor128.xpm"
# define DOOR "assets/exit/door_100_wfloor_128.xpm"

/* schrimp collectibles */
# define COLLECT "assets/schrimp/schrimp_collect_0_128.xpm"

/* struct */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_tileset
{
	t_data	*wfloor;
	t_data	*wwall;
	t_data	*collect;
	t_data	*exit;
}				t_tileset;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	int		moves;
	t_data	*pos_l;
	t_data	*pos_r;
	t_data	*pos_u;
	t_data	*pos_d;
}				t_player;

typedef struct s_v
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
}				t_v;

/* prototypes */
int			update(t_v *v);
int			k_inputs(int keycode, t_v *v);
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
int			backtrack_player(t_v *v, char *path);
int			backtrack_collect(t_v *v, char *path);
#endif
