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

int	close_window(t_vars *vars)
{
	unload_tileset(vars);
	unload_player(vars);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	mlx_destroy_display(vars->mlx_ptr);
	free_map(vars);
	return (0);
}

int	init_all(t_vars *vars, char *argv1)
{
	vars->map = get_map(argv1);
	if (!vars->map)
		return (map_error(NULL));
	printf("%i\n", check_map(vars->map, vars));
	print_map(vars->map);

	vars->mlx_ptr = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx_ptr, vars->map_w * STEP, vars->map_h * STEP, "Hello world!");

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

	mlx_key_hook(vars.mlx_win, &k_inputs, &vars);
	mlx_mouse_hook(vars.mlx_win, &m_inputs, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &close_window, &vars);
	mlx_loop_hook(vars.mlx_ptr, &update, &vars);
	mlx_loop(vars.mlx_ptr);
	free(vars.mlx_ptr);
}
