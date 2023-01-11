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

int	redraw(t_vars *vars)
{
	player_collect(vars);
	bg_pix_to_img(vars->img, WHITE);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
//	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->grass->img, 0, 0);
//	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wall->img, 0, 128);
	draw_floor(vars);
	draw_walls(vars);
	draw_player(vars);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 10, 10, GREEN, ft_itoa(vars->player->moves));
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 50, 10, GREEN, ft_itoa(vars->player->points));
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
			else if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->exit->img, (x * STEP), (y * STEP));
		}
	}
}

void	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_one->img, vars->player->x *STEP, vars->player->y * STEP);
}
