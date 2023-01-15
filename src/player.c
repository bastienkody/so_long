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

int load_player(t_vars *vars)
{
	t_player *player;

	player = malloc(1 * sizeof(t_player));
	if (!player)
		return (1);
	player->pos_left[0] = init_tile(vars, P_L_1);
	player->pos_left[1] = init_tile(vars, P_L_2);
	player->pos_left[2] = init_tile(vars, P_L_3);
	player->pos_left[3] = init_tile(vars, P_L_4);
	player->pos_right[0] = init_tile(vars, P_R_1);
	player->pos_right[1] = init_tile(vars, P_R_2);
	player->pos_right[2] = init_tile(vars, P_R_3);
	player->pos_right[3] = init_tile(vars, P_R_4);
	player->pos_up[0] = init_tile(vars, P_U_1);
	player->pos_up[1] = init_tile(vars, P_U_2);
	player->pos_up[2] = init_tile(vars, P_U_3);
	player->pos_up[3] = init_tile(vars, P_U_4);
	player->pos_down[0] = init_tile(vars, P_D_1);
	player->pos_down[1] = init_tile(vars, P_D_2);
	player->pos_down[2] = init_tile(vars, P_D_3);
	player->pos_down[3] = init_tile(vars, P_D_4);
	player->points = 0;
	player->moves = 0;
	player->static_moves = 0;
	player->static_delay = 0;
	player->dir = 'D';
	player->is_static = 1;
	vars->player = player;
	get_player_ini_pos(vars);
	return (0);
}

void unload_player(t_vars *vars)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_right[i]->img);
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_left[i]->img);
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_up[i]->img);
		mlx_destroy_image(vars->mlx_ptr, vars->player->pos_down[i]->img);
		free(vars->player->pos_right[i]);
		free(vars->player->pos_left[i]);
		free(vars->player->pos_up[i]);
		free(vars->player->pos_down[i]);
	}
	free(vars->player);
}

void move_player(int keycode, t_vars *vars)
{
	vars->player->moves += 1;
	vars->player->is_static = 0;
	vars->player->static_moves = 0;
	vars->player->static_delay = 0;
	if (keycode == W && !player_wall(vars, -1, 0))
	{
		vars->player->y -= 1;
		vars->player->dir = 'U';
	}
	if (keycode == S && !player_wall(vars, 1, 0))
	{
		vars->player->y += 1;
		vars->player->dir = 'D';
	}
	if (keycode == A && !player_wall(vars, 0, -1))
	{
		vars->player->x -= 1;
		vars->player->dir = 'L';
	}
	if (keycode == D && !player_wall(vars, 0, 1))
	{
		vars->player->x += 1;
		vars->player->dir = 'R';
	}
}