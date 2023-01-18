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
	draw_floor_wall(v);
	draw_door(v);
	draw_player(v);
	draw_score(v);
	draw_collect(v);
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
		v->shark[nb]->static_delay += 1;
		if (v->shark[nb]->static_delay > 5000)
		{
			move_shark(v, nb); 
			v->shark[nb]->static_delay = 0;
		}
	}
	nb = v->nb_enemies;
	while(--nb > -1)
	{
			draw_enemy(v, nb);
	}
	//ft_printf("sharkpos : x=%i, y=%i\n", v->shark[0]->x, v->shark[0]->y);
}

int	update(t_v *v)
{
	if (player_exit(v))
	{
		ft_printf("you won\n");
		close_window(v);
		return (0);
	}
	//if (
	player_collect(v);
		//redraw(v);
	v->player->static_delay += 1;
	if (v->player->static_delay > 3500)
	{
		v->player->static_delay = 0;
		v->player->static_moves += 1;
	}
	if (v->player->static_moves > 1)
		v->player->is_static = 1;
	v->c_anim += 1;
	if (v->c_anim > 40000)
		v->c_anim = 0;
	if (!(v->c_anim % 1000))
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
