/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:29:49 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:28 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	player_wall(t_vars *vars, int y_offset, int x_offset)
{
	if (vars->map[vars->player->y + y_offset][vars->player->x + x_offset] == '1')
		return (1);
	return (0);
}

int	player_exit(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'E' && !vars->c)
		return (1);
	return (0);
}

/* not used anymore we draw the door according the collectibles left */
int	player_abt_to_exit(t_vars *vars)
{
	if (vars->c > 0)
		return (0);
	if (vars->map[vars->player->y - 1][vars->player->x] == 'E')
		return (1);
	if (vars->map[vars->player->y + 1][vars->player->x] == 'E')
		return (1);
	if (vars->map[vars->player->y][vars->player->x - 1] == 'E')
		return (1);
	if (vars->map[vars->player->y][vars->player->x + 1] == 'E')
		return (1);
	return (0);
}

int	player_collect(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x] == 'C')
	{
		vars->c -= 1;
		vars->map[vars->player->y][vars->player->x] = '0';
		return (1);
	}
	return (0);
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