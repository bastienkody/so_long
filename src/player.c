/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:34:29 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/09 17:37:23 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	load_player(t_vars *vars)
{
	t_player	*player;

	player = malloc(1 * sizeof(t_player));
	if (!player)
		return (1);
	player->pos_left[0]= init_sprite(vars, POS_L_1);
	player->pos_left[1]= init_sprite(vars, POS_L_2);
	player->pos_left[2]= init_sprite(vars, POS_L_3);
	//player->pos_left[3]= init_sprite(vars, POS_L_4);
	player->pos_right[0]= init_sprite(vars, POS_R_1);
	player->pos_right[1]= init_sprite(vars, POS_R_2);
	player->pos_right[2]= init_sprite(vars, POS_R_3);
	//player->pos_right[3]= init_sprite(vars, POS_R_4);
	player->pos_static_l[0]= init_sprite(vars, POS_SL_1);
	player->pos_static_l[1]= init_sprite(vars, POS_SL_2);
	player->pos_static_l[2]= init_sprite(vars, POS_SL_3);
	player->pos_static_l[3]= init_sprite(vars, POS_SL_4);
	player->pos_static_r[0]= init_sprite(vars, POS_SR_1);
	player->pos_static_r[1]= init_sprite(vars, POS_SR_2);
	player->pos_static_r[2]= init_sprite(vars, POS_SR_3);
	player->pos_static_r[3]= init_sprite(vars, POS_SR_4);
	player->points = 0;
	player->moves = 0;
	player->l_moves = 0;
	player->r_moves = 0;
	player->static_moves = 0;
	player->static_delay = 0;
	player->dir = 'L';
	player->is_static = 1;
	vars->player = player;
	get_player_ini_pos(vars);
	return (0);
}

void	unload_player(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_right[i]->img);
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_left[i]->img);
		free(vars->player->pos_right[i]);
		free(vars->player->pos_left[i]);
	}
	free(vars->player);
}

t_data	*init_sprite(t_vars *vars, char *path)
{
	t_data	*sprite;
	int	w;	
	int	h;

	w = P_WIDTH;
	h = P_HEIGHT;
	sprite = malloc(1 * sizeof(t_data));
	if (!sprite)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(vars->mlx_ptr, path, &w, &h);
	if (!sprite->img)
		printf("xpm to img failed\n");
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
	return (sprite);
}

void	move_player(int keycode, t_vars *vars)
{
	if (keycode == W && !player_wall(vars, - 1, 0))
	{
		vars->player->y -= 1;
		vars->player->moves += 1;
		vars->player->r_moves = 0;
		vars->player->l_moves = 0;
		vars->player->is_static = 0;
		vars->player->static_moves = 0;
		vars->player->static_delay = 0;
	}
	if (keycode == A && !player_wall(vars, 0, -1))
	{
		vars->player->x -= 1;
		vars->player->dir = 'L';
		vars->player->moves += 1;
		vars->player->l_moves += 1;
		vars->player->is_static = 0;
		vars->player->static_moves = 0;
		vars->player->static_delay = 0;
	}
	if (keycode == S && !player_wall(vars, 1, 0))
	{
		vars->player->y += 1;
		vars->player->moves += 1;
		vars->player->r_moves = 0;
		vars->player->l_moves = 0;
		vars->player->is_static = 0;
		vars->player->static_moves = 0;
		vars->player->static_delay = 0;
	}
	if (keycode == D && !player_wall(vars, 0, 1))
	{
		vars->player->x += 1;
		vars->player->dir = 'R';
		vars->player->moves += 1;
		vars->player->r_moves += 1;
		vars->player->is_static = 0;
		vars->player->static_moves = 0;
		vars->player->static_delay = 0;
	}
}

/* player pos from map.ber */
void	get_player_ini_pos(t_vars *vars)
{
	int	x;
	int	y;

	if (!vars->player)
		return ;
	y = -1;
	while (++y < vars->map_h)
	{
		x = -1;
		while (++x < vars->map_w)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->player->x = x;
				vars->player->y = y;			
			}
		}
	}
}
