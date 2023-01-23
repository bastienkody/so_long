/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:47 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/16 11:03:54 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	draw_score(t_v *v)
{
	char	*moves;
	char	*collects;

	moves = ft_itoa(v->player->moves);
	collects = ft_itoa(v->current_c);
	mlx_string_put(v->ptr, v->win, 10, 15, BLACK, "moves:");
	mlx_string_put(v->ptr, v->win, 50, 15, BLACK, moves);
	mlx_string_put(v->ptr, v->win, 100, 15, BLACK, "collects:");
	mlx_string_put(v->ptr, v->win, 160, 15, BLACK, collects);
	free(moves);
	free(collects);
}

void	draw_floor_wall(t_v *v)
{
	int		x;
	int		y;
	char	*str;

	str = "CP0S";
	y = -1;
	while (++y < v->map_h)
	{
		x = -1;
		while (++x < v->map_w)
		{
			if (ft_strchr(str, v->map[y][x]))
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->wfloor->img, x * STEP, y * STEP);
			if (v->map[y][x] == '1')
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->wwall->img, x * STEP, y * STEP);
		}
	}
}

void	draw_door(t_v *v)
{
	int	x;
	int	y;

	y = -1;
	while (++y < v->map_h)
	{
		x = -1;
		while (++x < v->map_w)
		{
			if (v->map[y][x] == 'E' && v->current_c == v->ini_c)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->exit[3]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'E' && v->current_c >= v->ini_c * 3 / 4)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->exit[2]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'E' && v->current_c >= v->ini_c * 1 / 2)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->exit[1]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'E')
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->exit[0]->img, x * STEP, y * STEP);
		}
	}
}

void	draw_collect(t_v *v)
{
	int	x;
	int	y;

	y = -1;
	while (++y < v->map_h)
	{
		x = -1;
		while (++x < v->map_w)
		{
			if (v->map[y][x] == 'C' && v->c_anim < C_STEP_UBU)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->collect[0]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'C' && v->c_anim < 2 * C_STEP_UBU)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->collect[1]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'C' && v->c_anim < 3 * C_STEP_UBU)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->collect[2]->img, x * STEP, y * STEP);
			else if (v->map[y][x] == 'C' && v->c_anim > 3 * C_STEP_UBU)
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->collect[3]->img, x * STEP, y * STEP);
		}
	}
}

void	draw_player(t_v *v)
{
	int	x;
	int	y;
	int	moves;

	x = v->player->x * STEP;
	y = v->player->y * STEP;
	moves = v->player->moves;
	if (v->player->is_static)
		moves = v->player->static_moves;
	if (v->player->dir == 'L')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_l[moves % 4]->img, x, y);
	else if (v->player->dir == 'R')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_r[moves % 4]->img, x, y);
	else if (v->player->dir == 'U')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_u[moves % 4]->img, x, y);
	else if (v->player->dir == 'D')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_d[moves % 4]->img, x, y);
}
