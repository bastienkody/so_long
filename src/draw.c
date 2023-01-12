/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:47 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/09 17:36:05 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_score(t_vars *vars)
{
	char	*moves;
	char	*points;

	moves = ft_itoa(vars->player->moves);
	points = ft_itoa(vars->player->points);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 10, 15, BLACK, "moves:");
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 70, 15, BLACK, moves);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 100, 15, BLACK, "points:");
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 170, 15, BLACK, points);
	free(moves);
	free(points);
}

int	redraw(t_vars *vars)
{
	draw_floor(vars);
	draw_walls(vars);
	draw_player(vars);
	draw_score(vars);
	return (0);
}

void	draw_floor(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map_h)
	{
		x = -1;
		while (++x < vars->map_w)
		{
			if (vars->map[y][x] == '0' || vars->map[y][x] == 'C' || vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->grass->img, (x * STEP), (y * STEP));
		}
	}
}

void	draw_walls(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map_h)
	{
		x = -1;
		while (++x < vars->map_w)
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wall->img, (x * STEP), (y * STEP));
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->collect->img, (x * STEP), (y * STEP));
			else if (vars->map[y][x] == 'E' && player_abt_to_exit(vars))
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[1]->img, (x * STEP), (y * STEP));
			else if (vars->map[y][x] == 'E' && !player_abt_to_exit(vars))
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[0]->img, (x * STEP), (y * STEP));	
		}
	}
}

void	draw_player(t_vars *vars)
{
	if (vars->player->is_static && vars->player->dir == 'L')
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_static_l[vars->player->static_moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
	else if (vars->player->is_static && vars->player->dir == 'R')
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_static_r[vars->player->static_moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
	else if (vars->player->dir == 'L')
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_left[vars->player->l_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
	else if (vars->player->dir == 'R')
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_right[vars->player->r_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
}
