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

int	update(t_v *v)
{
	if (player_exit(v))
	{
		ft_fprintf(1, "You ate all schrimps and left. You won\n");
		close_window(v);
		return (0);
	}
	draw_collect(v);
	draw_player(v);
	return (0);
}

int	k_inputs(int kcode, t_v *v)
{
	if (kcode == XK_Escape)
	{
		close_window(v);
		return (0);
	}
	else if (kcode == XK_w || kcode == XK_a || kcode == XK_s || kcode == XK_d)
		move_player(kcode, v);
	player_collect(v);
	redraw(v);
	return (0);
}
