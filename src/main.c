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

int	close_window(t_vars *vars)
{
	unload_tileset(vars);
	unload_player(vars);
	//XUnloadFont(vars->mlx_ptr, FONT);
	mlx_destroy_window(vars->ptr, vars->win);
	free_map(vars);
	mlx_destroy_display(vars->ptr);
	free(vars->ptr);
	ft_printf("c:%i\n", vars->current_c);
	exit(EXIT_SUCCESS);
}

int	init_all(t_vars *vars, char *argv1)
{
	vars->ini_c = 0;
	vars->current_c = 0;
	vars->c_anim = 0;
	vars->map = get_map(argv1);
	if (!vars->map)
		return (map_error(NULL));
	if (check_map(vars->map, vars))
		return(1);
	print_map(vars->map);

	vars->ptr = mlx_init();
	vars->win = mlx_new_window(vars->ptr, vars->map_w * STEP, vars->map_h * STEP, "So_long!");

	if (load_tileset(vars))
	{
		printf("free-all and quit (erreur malloc tileset)\n");
		return (1);
	}	
	if (load_player(vars))
	{
		printf("free-all and quit (erreur malloc player)\n");
		return (1);
	}
	//mlx_set_font(vars->mlx_ptr, vars->mlx_win, FONT);
	redraw(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (arg_error(argc, argv))
		return (1);
	if (init_all(&vars, argv[1]))
		return (1);
	ft_printf("vars.map_h:%i\n", vars.map_h);
	ft_printf("vars.map_w:%i\n", vars.map_w);
	ft_printf("vars.ini_c:%i\n", vars.ini_c);

	mlx_key_hook(vars.win, &k_inputs, &vars);
	mlx_mouse_hook(vars.win, &m_inputs, &vars);
	mlx_hook(vars.win, 17, 0, &close_window, &vars);
	mlx_loop_hook(vars.ptr, &update, &vars);
	mlx_loop(vars.ptr);
}
