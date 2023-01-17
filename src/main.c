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

#include "../inc/so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(t_v *v)
{
	free_map(v);
	if (v->tileset)
		unload_tileset(v);
	if (v->player)
		unload_player(v);
	mlx_destroy_window(v->ptr, v->win);
	mlx_destroy_display(v->ptr);
	free(v->ptr);
	ft_printf("c:%i\n", v->current_c);
	exit(EXIT_SUCCESS);
}

int	init_all(t_v *v, char *argv1)
{
	v->ini_c = 0;
	v->current_c = 0;
	v->c_anim = 0;
	v->map = get_map(argv1);
	if (!v->map)
		return (map_error(NULL));
	if (check_map(v->map, v))
		return (1);
	v->ptr = mlx_init();
	v->win = mlx_new_window(v->ptr, v->map_w * STEP, 
			v->map_h * STEP, "slg");
	if (load_tileset(v))
	{
		printf("free-all and quit (erreur malloc tileset)\n");
		return (1);
	}	
	if (load_player(v))
	{
		printf("free-all and quit (erreur malloc player)\n");
		return (1);
	}
	//mlx_set_font(v->mlx_ptr, v->mlx_win, FONT);
	redraw(v);
	return (0);
}

int	main(int argc, char **argv)
{
	t_v	v;

	if (arg_error(argc, argv))
		return (1);
	if (init_all(&v, argv[1]))
		return (1);

	mlx_key_hook(v.win, &k_inputs, &v);
	mlx_mouse_hook(v.win, &m_inputs, &v);
	mlx_hook(v.win, 17, 0, &close_window, &v);
	mlx_loop_hook(v.ptr, &update, &v);
	mlx_loop(v.ptr);
}
