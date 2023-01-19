/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:23:52 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/16 11:03:59 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	redraw(t_v *v)
{
	int	nb;

	draw_floor_wall(v);
	draw_door(v);
	draw_collect(v);
	draw_score(v);
	nb = v->nb_enemies;
	while(--nb > -1)
	{
			draw_enemy(v, nb);
	}
	draw_player(v);
	return (0);
}

void	update_shark(t_v *v)
{
	int	nb;

	if (!v->shark)
		return ;
	nb = v->nb_enemies;
	while(--nb > -1)
	{
		v->shark[nb]->delay += 1;
		if (v->shark[nb]->delay > SHARK_TIMER_MAC)
		{
			v->shark[nb]->delay = 0;
			if (move_shark(v, nb))
				redraw(v); 
		}
	}
	//ft_printf("sharkpos : x=%i, y=%i\n", v->shark[0]->x, v->shark[0]->y);
}

int	update(t_v *v)
{
	if (shark_player(v))
	{
		ft_printf("Shark ate you. You loose\n");
		close_window(v);
	}
	if (player_exit(v))
	{
		ft_printf("You ate all schrimps and left. You won\n");
		close_window(v);
		return (0);
	}
	player_collect(v);
	v->player->static_delay += 1;
	if (v->player->static_delay > PLAY_S_DELAY_MAC)
	{
		v->player->static_delay = 0;
		v->player->static_moves += 1;
	}
	if (v->player->static_moves > 1)
		v->player->is_static = 1;
	v->c_anim += 1;
	if (v->c_anim > C_ANIM_MAC)
		v->c_anim = 0;
	if (!(v->c_anim % C_STEP_MAC))
		draw_collect(v);
	update_shark(v);
	draw_player(v);
	return (0);
}

int	k_inputs(int keycode, t_v *v)
{
	if (keycode == ESC)
	{
		close_window(v);
		return (0);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, v);
	redraw(v);
	return (0);
}

int	m_inputs(int button, int x, int y, t_v *v)
{
	printf("M_button %i\n", button);
	printf("M_x %i\n", x);
	printf("M_y %i\n", y);
	printf("v%p\n", v);
	if (button == LEFT_C)
		printf("left_clic\n");
	if (button == RIGHT_C)
		printf("right_clic\n");
	return (0);
}
