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
	char	*collects;

	moves = ft_itoa(vars->player->moves);
	collects = ft_itoa(vars->c);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 10, 15, BLACK, "moves:");
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 70, 15, BLACK, moves);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 100, 15, BLACK, "collects:");
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 180, 15, BLACK, collects);
	free(moves);
	free(collects);
}

int	redraw(t_vars *vars)
{
	draw_floor_wall(vars);
	//draw_collect_door(vars);
	draw_player(vars);
	draw_score(vars);
	return (0);
}

void	draw_floor_wall(t_vars *vars)
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
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wfloor->img, (x * STEP), (y * STEP));
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wwall->img, (x * STEP), (y * STEP));
		}
	}
}

void	draw_collect_door(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map_h)
	{
		x = -1;
		while (++x < vars->map_w)
		{
			if (vars->map[y][x] == 'C' && vars->c_anim < 50)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->collect[0]->img, (x * STEP), (y * STEP));
			if (vars->map[y][x] == 'C' && vars->c_anim > 50 && vars->c_anim < 100)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->collect[1]->img, (x * STEP), (y * STEP));
			if (vars->map[y][x] == 'C' && vars->c_anim > 100 && vars->c_anim < 150)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->collect[2]->img, (x * STEP), (y * STEP));
			if (vars->map[y][x] == 'C' && vars->c_anim > 150)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->collect[3]->img, (x * STEP), (y * STEP));
			
			
			
			
			else if (vars->map[y][x] == 'E' && !vars->c)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[3]->img, (x * STEP), (y * STEP));
			else if (vars->map[y][x] == 'E' && vars->c == 1)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[2]->img, (x * STEP), (y * STEP));	
			else if (vars->map[y][x] == 'E' && vars->c == 2)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[1]->img, (x * STEP), (y * STEP));
			else if (vars->map[y][x] == 'E' && vars->c > 2)
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit[0]->img, (x * STEP), (y * STEP));		
		}
	}
}

void	draw_player(t_vars *vars)
{
	if (vars->player->is_static)
	{
		if (vars->player->is_static && vars->player->dir == 'L')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_left[vars->player->static_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->is_static && vars->player->dir == 'R')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_right[vars->player->static_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->is_static && vars->player->dir == 'U')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_up[vars->player->static_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->is_static && vars->player->dir == 'D')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_down[vars->player->static_moves % 3]->img, vars->player->x *STEP, vars->player->y * STEP);
	}
	else
	{	
		if (vars->player->dir == 'L')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_left[vars->player->moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->dir == 'R')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_right[vars->player->moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->dir == 'U')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_up[vars->player->moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
		else if (vars->player->dir == 'D')
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_down[vars->player->moves % 4]->img, vars->player->x *STEP, vars->player->y * STEP);
	}
}
