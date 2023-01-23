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

int	check_load_tileset(t_tileset *tileset)
{
	if (!tileset->wfloor || !tileset->wwall)
		return (1);
	if (!tileset->collect || !tileset->exit)
		return (1);
	return (0);
}

int	load_tileset(t_v *v)
{
	t_tileset	*tileset;

	tileset = malloc(1 * sizeof(t_tileset));
	if (!tileset)
		return (1);
	tileset->wfloor = init_tile(v, WFLOOR);
	tileset->wwall = init_tile(v, WWALL);
	tileset->collect = init_tile(v, COLLECT);
	tileset->exit = init_tile(v, DOOR);
	v->tileset = tileset;
	if (check_load_tileset(tileset))
		return (1);
	return (0);
}

void	unload_tileset(t_v *v)
{
	if (v->tileset->wfloor && v->tileset->wfloor->img)
		mlx_destroy_image(v->ptr, v->tileset->wfloor->img);
	if (v->tileset->wfloor)
		free(v->tileset->wfloor);
	if (v->tileset->wwall && v->tileset->wwall->img)
		mlx_destroy_image(v->ptr, v->tileset->wwall->img);
	if (v->tileset->wwall)
		free(v->tileset->wwall);
	if (v->tileset->exit && v->tileset->exit->img)
		mlx_destroy_image(v->ptr, v->tileset->exit->img);
	if (v->tileset->collect && v->tileset->collect->img)
		mlx_destroy_image(v->ptr, v->tileset->collect->img);
	if (v->tileset->exit)
		free(v->tileset->exit);
	if (v->tileset->collect)
		free(v->tileset->collect);
	free(v->tileset);
}

t_data	*init_tile(t_v *v, char *path)
{
	t_data	*tile;
	int		w;	
	int		h;

	w = T_WIDTH;
	h = T_HEIGHT;
	tile = malloc(1 * sizeof(t_data));
	tile->img = mlx_xpm_file_to_image(v->ptr, path, &w, &h);
	if (!tile->img)
	{
		free(tile);
		return (NULL);
	}
	return (tile);
}
