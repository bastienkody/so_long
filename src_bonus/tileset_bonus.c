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

#include "../inc/so_long_bonus.h"

int	check_load_tileset(t_tileset *tileset)
{
	int	i;

	if (!tileset->wfloor || !tileset->wwall)
		return (1);
	i = -1;
	while (++i < 4)
	{
		if (!tileset->collect[i] || !tileset->exit[i])
			return (1);
	}
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
	tileset->collect[0] = init_tile(v, COLLECT_0);
	tileset->collect[1] = init_tile(v, COLLECT_1);
	tileset->collect[2] = init_tile(v, COLLECT_2);
	tileset->collect[3] = init_tile(v, COLLECT_3);
	tileset->exit[0] = init_tile(v, DOOR_100);
	tileset->exit[1] = init_tile(v, DOOR_75);
	tileset->exit[2] = init_tile(v, DOOR_25);
	tileset->exit[3] = init_tile(v, DOOR_0);
	v->tileset = tileset;
	if (check_load_tileset(tileset))
		return (1);
	return (0);
}

void	unload_tileset(t_v *v)
{
	int	i;

	if (v->tileset->wfloor && v->tileset->wfloor->img)
		mlx_destroy_image(v->ptr, v->tileset->wfloor->img);
	if (v->tileset->wfloor)
		free(v->tileset->wfloor);
	if (v->tileset->wwall && v->tileset->wwall->img)
		mlx_destroy_image(v->ptr, v->tileset->wwall->img);
	if (v->tileset->wwall)
		free(v->tileset->wwall);
	i = -1;
	while (++i < 4)
	{
		if (v->tileset->exit[i] && v->tileset->exit[i]->img)
			mlx_destroy_image(v->ptr, v->tileset->exit[i]->img);
		if (v->tileset->collect[i] && v->tileset->collect[i]->img)
			mlx_destroy_image(v->ptr, v->tileset->collect[i]->img);
		if (v->tileset->exit[i])
			free(v->tileset->exit[i]);
		if (v->tileset->collect[i])
			free(v->tileset->collect[i]);
	}
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
