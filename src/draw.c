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

#include "../inc/so_long.h"

void	draw_score(t_v *v)
{
	ft_fprintf(1, "moves : %i\n", v->player->moves);
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
			if (v->map[y][x] == 'E')
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->exit->img, x * STEP, y * STEP);
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
			if (v->map[y][x] == 'C')
				mlx_put_image_to_window(v->ptr, v->win,
					v->tileset->collect->img, x * STEP, y * STEP);
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
	if (v->player->dir == 'L')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_l->img, x, y);
	else if (v->player->dir == 'R')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_r->img, x, y);
	else if (v->player->dir == 'U')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_u->img, x, y);
	else if (v->player->dir == 'D')
		mlx_put_image_to_window(v->ptr, v->win,
			v->player->pos_d->img, x, y);
}
