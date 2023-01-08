/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:47 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 13:20:28 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	redraw(t_vars *vars)
{
	bg_pix_to_img(vars->img, WHITE);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
//	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->grass->img, 0, 0);
//	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wall->img, 0, 128);
	draw_floor(vars);
	draw_walls(vars);
	draw_player(vars);
	mlx_string_put(vars->mlx_ptr, vars->mlx_win, 10, 10, GREEN, ft_itoa(vars->moves));
	return (0);
}

void	draw_floor(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->grass->img, x, y);
			y += T_HEIGHT;	
		}
		x += T_WIDTH;
	}
}

void	draw_walls(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (x == 0 || x == WIDTH - T_WIDTH || y == 0 || y == HEIGHT - T_HEIGHT)
			{
				printf("x:%i, y:%i\n", x, y);
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->tileset->wall->img, x, y);
			}
			y += T_HEIGHT;	
		}
		x += T_WIDTH;
	}
}

void	draw_player(t_vars *vars)
{
	int	x;
	int	y;

	if (!vars->player)
		return ;
	x = vars->player->x;
	y = vars->player->y;
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->player->pos_one->img, x, y);
}
