/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:23:52 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/12 16:27:23 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	update(t_vars *vars)
{
	player_collect(vars);
	vars->player->static_delay += 1;
	if (vars->player->static_delay > 2500)
	{
		vars->player->static_delay = 0;
		vars->player->static_moves += 1;
	}
	if (vars->player->static_moves > 2)
		vars->player->is_static = 1;
	draw_player(vars);
	return (0);
}

int	k_inputs(int keycode, t_vars *vars)
{
//	printf("keycode : %i\n", keycode);
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, vars);
	if (player_exit(vars))
	{
		ft_printf("you won\n");
		close_window(vars);
	}
	redraw(vars);
	return (0);
}

int	m_inputs(int button, int x, int y, t_vars *vars)
{
	printf("M_button %i\n", button);
	printf("M_x %i\n", x);
	printf("M_y %i\n", y);
	printf("vars%p\n", vars);
	if (button == LEFT_C)
		printf("left_clic\n");
	if (button == RIGHT_C)
		printf("right_clic\n");
	return (0);
}