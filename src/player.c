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

void	init_player(t_player *player, t_v *v)
{
	int	x;
	int	y;

	if (!player || !v)
		return ;
	v->player = player;
	v->player->points = 0;
	v->player->moves = 0;
	v->player->static_moves = 0;
	v->player->static_delay = 0;
	v->player->dir = 'D';
	v->player->is_static = 1;
	y = -1;
	while (++y < v->map_h)
	{
		x = -1;
		while (++x < v->map_w)
		{
			if (v->map[y][x] == 'P')
			{
				v->player->x = x;
				v->player->y = y;
			}
		}
	}
}

int	check_load_player(t_player *player)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!player->pos_l[i] || !player->pos_r[i] || !player->pos_u[i]
			|| !player->pos_d[i])
			return (1);
	}
	return (0);
}

int	load_player(t_v *v)
{
	t_player	*player;

	player = malloc(1 * sizeof(t_player));
	if (!player)
		return (1);
	player->pos_l[0] = init_tile(v, P_L_1);
	player->pos_l[1] = init_tile(v, P_L_2);
	player->pos_l[2] = init_tile(v, P_L_3);
	player->pos_l[3] = init_tile(v, P_L_4);
	player->pos_r[0] = init_tile(v, P_R_1);
	player->pos_r[1] = init_tile(v, P_R_2);
	player->pos_r[2] = init_tile(v, P_R_3);
	player->pos_r[3] = init_tile(v, P_R_4);
	player->pos_u[0] = init_tile(v, P_U_1);
	player->pos_u[1] = init_tile(v, P_U_2);
	player->pos_u[2] = init_tile(v, P_U_3);
	player->pos_u[3] = init_tile(v, P_U_4);
	player->pos_d[0] = init_tile(v, P_D_1);
	player->pos_d[1] = init_tile(v, P_D_2);
	player->pos_d[2] = init_tile(v, P_D_3);
	player->pos_d[3] = init_tile(v, P_D_4);
	init_player(player, v);
	if (check_load_player(player))
		return (1);
	return (0);
}

void	unload_player(t_v *v)
{
	int	i;

	i = -1;
	if (!v->player)
		return ;
	while (++i < 4)
	{
		if (v->player->pos_r[i] && v->player->pos_r[i]->img)
			mlx_destroy_image(v->ptr, v->player->pos_r[i]->img);
		if (v->player->pos_l[i] && v->player->pos_l[i]->img)
			mlx_destroy_image(v->ptr, v->player->pos_l[i]->img);
		if (v->player->pos_u[i] && v->player->pos_u[i]->img)
			mlx_destroy_image(v->ptr, v->player->pos_u[i]->img);
		if (v->player->pos_d[i] && v->player->pos_d[i]->img)
			mlx_destroy_image(v->ptr, v->player->pos_d[i]->img);
		if (v->player->pos_r[i])
			free(v->player->pos_r[i]);
		if (v->player->pos_l[i])
			free(v->player->pos_l[i]);
		if (v->player->pos_u[i])
			free(v->player->pos_u[i]);
		if (v->player->pos_d[i])
			free(v->player->pos_d[i]);
	}
	free(v->player);
}

void	move_player(int keycode, t_v *v)
{
	v->player->moves += 1;
	v->player->is_static = 0;
	v->player->static_moves = 0;
	v->player->static_delay = 0;
	if (keycode == W && !player_wall(v, -1, 0))
	{
		v->player->y -= 1;
		v->player->dir = 'U';
	}
	if (keycode == S && !player_wall(v, 1, 0))
	{
		v->player->y += 1;
		v->player->dir = 'D';
	}
	if (keycode == A && !player_wall(v, 0, -1))
	{
		v->player->x -= 1;
		v->player->dir = 'L';
	}
	if (keycode == D && !player_wall(v, 0, 1))
	{
		v->player->x += 1;
		v->player->dir = 'R';
	}
}
