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

int	load_player(t_vars *vars)
{
	t_player	*player;

	player = malloc(1 * sizeof(t_player));
	if (!player)
		return (1);	
	player->pos_one = init_sprite(vars, POS_ONE_P);
	vars->player = player;
	get_player_ini_pos(vars);
	ft_printf("player loaded :%p\n", player);
	return (0);
}

void	unload_player(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->player->pos_one->img);
	free(vars->player->pos_one);
	free(vars->player);
}

t_data	*init_sprite(t_vars *vars, char *path)
{
	t_data	*sprite;
	int	w;	
	int	h;

	w = P_WIDTH;
	h = P_HEIGHT;
	sprite = malloc(1 * sizeof(t_data));
	if (!sprite)
		return (NULL);
	sprite->img = mlx_xpm_file_to_image(vars->mlx_ptr, path, &w, &h);
	if (!sprite->img)
		printf("xpm to img failed\n");
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
	return (sprite);
}

void	move_player(int keycode, t_vars *vars)
{
	if (keycode == W)
	{
		vars->player->y -= STEP;
	}
	if (keycode == A)
	{
		vars->player->x -= STEP;
	}
	if (keycode == S)
	{
		vars->player->y += STEP;
	}
	if (keycode == D)
	{
		vars->player->x += STEP;
	}
	vars->moves += 1;
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
				vars->player->x = x * STEP;
				vars->player->y = y * STEP;			
				ft_printf("player pos x:%i, y:%i\n", x, y);
			}
		}
	}
}
