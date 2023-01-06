/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:05 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 19:09:00 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	close_window(t_vars *vars)
{
	mlx_destroy_display(vars->mlx_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	return (0);
}

int	k_inputs(int keycode, t_vars *vars)
{
	printf("keycode : %i\n", keycode);
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, vars);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		printf("arrows keys");
//	redraw(vars);
	printf("player.x : %i\n", vars->player->x);
	printf("player.y : %i\n", vars->player->y);
	return (0);
}

int	m_inputs(int button, int x, int y, t_vars *vars)
{
	printf("M_button %i\n", button);
	printf("M_x %i\n", x);
	printf("M_y %i\n", y);
	printf("vars:%p\n", vars);
	if (button == LEFT_C)
		printf("left_clic\n");
	if (button == RIGHT_C)
		printf("right_clic\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	if (argc != 2)
		return (arg_error());
	vars.map = get_map(argv[1]);
	if (!vars.map)
		return (map_error(NULL));
	print_map(vars.map);
//	while (*(vars.map))
//		printf("%s\n", *(vars.map)++);
	check_map(vars.map);

	return (0);

	vars.mlx_ptr = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "Hello world!");
	vars.moves = 0;

	img.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;

	if (load_tileset(&vars))
		printf("free-all and quit (erreur malloc tileset)\n");
	
	if (load_player(&vars))
		printf("free-all and quit (erreur malloc player)\n");

	mlx_key_hook(vars.mlx_win, &k_inputs, &vars);
	mlx_mouse_hook(vars.mlx_win, &m_inputs, &vars);
	mlx_hook(vars.mlx_win, 17, 0, &close_window, &vars);
	mlx_loop_hook(vars.mlx_ptr, &redraw, &vars);
	mlx_loop(vars.mlx_ptr);

	unload_tileset(&vars);
//	mlx_destroy_window(vars.mlx_ptr, vars.mlx_win);
	mlx_destroy_image(vars.mlx_ptr, img.img);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
}
