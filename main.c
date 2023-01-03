/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:05 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/03 20:35:20 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	k_inputs(int keycode, t_vars *vars)
{
	printf("keycode : %i\n", keycode);
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_rect(keycode, vars);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		resize_rect(keycode, vars);
	return (0);
}

int	m_inputs(int button, int x, int y, t_vars *vars)
{
	t_rect	*new_rect;

	printf("M_button %i\n", button);
	printf("M_x %i\n", x);
	printf("M_y %i\n", y);
	if (button == LEFT_C)
	{
		pix_to_img(vars->img, x, y, BLACK);
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
	}
	if (button == RIGHT_C)
	{
		new_rect = malloc(sizeof(t_rect));
		init_t_rect(new_rect, x, y, 10, 10);
//		vars->rect = new_rect;
//		draw_rects(vars);
		rect_pix_to_img(vars->img, new_rect, GREEN);
		mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
	}
	print_rects(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_rect	rect;

	vars.mlx_ptr = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "Hello world!");

	img.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;

	bg_pix_to_img(&img, WHITE);
	init_t_rect(&rect, 250, 250, 600, 600);
	vars.rect = &rect;
	rect_pix_to_img(&img, rect, RED);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, img.img, 0, 0);

	mlx_do_key_autorepeaton(vars.mlx_ptr);
	mlx_key_hook(vars.mlx_win, &k_inputs, &vars);
	mlx_mouse_hook(vars.mlx_win, &m_inputs, &vars);

	mlx_loop(vars.mlx_ptr);
	mlx_destroy_window(vars.mlx_ptr, vars.mlx_win);
	mlx_destroy_image(vars.mlx_ptr, img.img);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
}
