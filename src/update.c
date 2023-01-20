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

void	update_shark(t_v *v)
{
	int	nb;

	if (!v->shark)
		return ;
	nb = v->nb_enemies;
	while (--nb > -1)
	{
		if (!v->shark[nb]->is_alive)
			continue ;
		v->shark[nb]->delay += 1;
		if (v->shark[nb]->delay > SHARK_TIMER_UBU)
		{
			v->shark[nb]->delay = 0;
			if (move_shark(v, nb))
				redraw(v);
		}
	}
}

void	update_anim(t_v *v)
{
	v->player->static_delay += 1;
	if (v->player->static_delay > PLAY_S_DELAY_UBU)
	{
		v->player->is_static = 1;
		v->player->static_delay = 0;
		v->player->static_moves += 1;
	}
	v->c_anim += 1;
	if (v->c_anim > C_ANIM_UBU)
		v->c_anim = 0;
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
	update_anim(v);
	if (!(v->c_anim % C_STEP_UBU))
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
	player_collect(v);
	redraw(v);
	return (0);
}

int	m_inputs(int but, int x, int y, t_v *v)
{
	int	nb;

	nb = v->nb_enemies;
	x /= STEP;
	y /= STEP;
	while (--nb > -1)
	{
		if (v->shark[nb]->is_alive)
		{
			if (but == LEFT_C && x == v->shark[nb]->x && y == v->shark[nb]->y)
			{
				ft_printf("One shark has been killed\n");
				v->shark[nb]->is_alive = 0;
			}
		}
	}
	redraw(v);
	return (0);
}
