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
	tileset->grass = init_tile(vars, GRASS_P);
	tileset->wall = init_tile(vars, WALL_P);
	tileset->collect = init_tile(vars, COLLECT_P);
	tileset->exit[0] = init_tile(vars, EXIT_P);
	tileset->exit[1] = init_tile(vars, EXIT_OPEN_P);
	vars->tileset = tileset;
	return (0);
}

void	unload_tileset(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->grass->img);
	free(vars->tileset->grass);
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->wall->img);
	free(vars->tileset->wall);
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->collect->img);
	free(vars->tileset->collect);
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->exit[0]->img);
	free(vars->tileset->exit[0]);
	mlx_destroy_image(vars->mlx_ptr, vars->tileset->exit[1]->img);
	free(vars->tileset->exit[1]);
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
