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
	v->player->dir = 'D';
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
	if (!player->pos_l || !player->pos_r || !player->pos_u|| !player->pos_d)
		return (1);
	return (0);
}

int	load_player(t_v *v)
{
	t_player	*player;

	player = malloc(1 * sizeof(t_player));
	if (!player)
		return (1);
	player->pos_l = init_tile(v, P_L);
	player->pos_r = init_tile(v, P_R);
	player->pos_u = init_tile(v, P_U);
	player->pos_d = init_tile(v, P_D);
	init_player(player, v);
	if (check_load_player(player))
		return (1);
	return (0);
}

void	unload_player(t_v *v)
{
	if (!v->player)
		return ;
	if (v->player->pos_r && v->player->pos_r->img)
		mlx_destroy_image(v->ptr, v->player->pos_r->img);
	if (v->player->pos_l && v->player->pos_l->img)
		mlx_destroy_image(v->ptr, v->player->pos_l->img);
	if (v->player->pos_u && v->player->pos_u->img)
		mlx_destroy_image(v->ptr, v->player->pos_u->img);
	if (v->player->pos_d && v->player->pos_d->img)
		mlx_destroy_image(v->ptr, v->player->pos_d->img);
	if (v->player->pos_r)
		free(v->player->pos_r);
	if (v->player->pos_l)
		free(v->player->pos_l);
	if (v->player->pos_u)
		free(v->player->pos_u);
	if (v->player->pos_d)
		free(v->player->pos_d);
	free(v->player);
}

void	move_player(int keycode, t_v *v)
{
	v->player->moves += 1;
	if (keycode == XK_w && !player_wall(v, -1, 0))
	{
		v->player->y -= 1;
		v->player->dir = 'U';
	}
	else if (keycode == XK_s && !player_wall(v, 1, 0))
	{
		v->player->y += 1;
		v->player->dir = 'D';
	}
	else if (keycode == XK_a && !player_wall(v, 0, -1))
	{
		v->player->x -= 1;
		v->player->dir = 'L';
	}
	else if (keycode == XK_d && !player_wall(v, 0, 1))
	{
		v->player->x += 1;
		v->player->dir = 'R';
	}
}
