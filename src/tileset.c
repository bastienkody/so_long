/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tileset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:58:00 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 11:47:20 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	load_tileset(t_vars *vars)
{
	t_tileset	*tileset;

	tileset = malloc(1 * sizeof(t_tileset));
	if (!tileset)
		return (1);	
	tileset->wfloor = init_tile(vars, WFLOOR);
	tileset->wwall = init_tile(vars, WWALL);
	tileset->collect[0] = init_tile(vars, COLLECT_0);
	tileset->collect[1] = init_tile(vars, COLLECT_1);
	tileset->collect[2] = init_tile(vars, COLLECT_2);
	tileset->collect[3] = init_tile(vars, COLLECT_3);
	tileset->exit[0] = init_tile(vars, DOOR_100);
	tileset->exit[1] = init_tile(vars, DOOR_75);
	tileset->exit[2] = init_tile(vars, DOOR_25);
	tileset->exit[3] = init_tile(vars, DOOR_0);
	vars->tileset = tileset;
	return (0);
}

void	unload_tileset(t_vars *vars)
{
	int	i;
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->wfloor->img);
	free(vars->tileset->wfloor);
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->wwall->img);
	free(vars->tileset->wwall);
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->tileset->exit[i]->img);
		mlx_destroy_image(vars->mlx_ptr, vars->tileset->collect[i]->img);
		free(vars->tileset->exit[i]);
		free(vars->tileset->collect[i]);
	}
	free(vars->tileset);
}

t_data	*init_tile(t_vars *vars, char *path)
{
	t_data	*tile;
	int	w;	
	int	h;

	w = T_WIDTH;
	h = T_HEIGHT;
	tile = malloc(1 * sizeof(t_data));
	tile->img = mlx_xpm_file_to_image(vars->mlx_ptr, path, &w, &h);
	if (!tile->img)
		printf("xpm to img failed\n");
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel, &tile->line_length, &tile->endian);
	return (tile);
}
