/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:05 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/12 20:22:54 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	redraw(t_v *v)
{
	int	nb;

	draw_floor_wall(v);
	draw_door(v);
	draw_collect(v);
	draw_score(v);
	nb = v->nb_enemies;
	while (--nb > -1)
		draw_shark(v, nb);
	draw_player(v);
	return (0);
}

int	close_window(t_v *v)
{
	if (v->map)
		free_map(v, v->map);
	if (v->tileset)
		unload_tileset(v);
	if (v->player)
		unload_player(v);
	while (v->nb_enemies)
	{
		v->nb_enemies--;
		unload_shark(v, v->nb_enemies);
	}
	if (v->shark)
		free (v->shark);
	if (v->ptr)
	{
		if (v->win)
			mlx_destroy_window(v->ptr, v->win);
		mlx_destroy_display(v->ptr);
		free(v->ptr);
	}
	exit(EXIT_SUCCESS);
}

int	init_basics(t_v *v, char *argv1)
{
	v->tileset = NULL;
	v->player = NULL;
	v->shark = NULL;
	v->ini_c = 0;
	v->current_c = 0;
	v->c_anim = 0;
	v->nb_enemies = 0;
	v->map = get_map(argv1);
	if (!v->map)
		return (map_error(NULL));
	if (check_map(v->map, v))
		return (1);
	if (backtrack_player(v, argv1) || backtrack_collect(v, argv1))
		return (1);
	v->ptr = mlx_init();
	if (!v->ptr)
		return (1);
	v->win = mlx_new_window(v->ptr, v->map_w * STEP,
			v->map_h * STEP, "So_long");
	if (load_tileset(v))
		return (1);
	if (load_player(v))
		return (1);
	return (0);
}

int	init_enemies(t_v *v)
{
	if (get_enemies_from_map(v))
		return (0);
	if (init_sharks(v))
		return (close_window(v));
	return (0);
}

int	main(int argc, char **argv)
{
	t_v	v;

	v.ptr = NULL;
	v.win = NULL;
	if (arg_error(argc, argv))
		return (1);
	if (init_basics(&v, argv[1]))
		return (close_window(&v));
	if (init_enemies(&v))
		return (1);
	redraw(&v);
	mlx_key_hook(v.win, &k_inputs, &v);
	mlx_mouse_hook(v.win, &m_inputs, &v);
	mlx_hook(v.win, 17, 0, &close_window, &v);
	mlx_loop_hook(v.ptr, &update, &v);
	mlx_loop(v.ptr);
}
