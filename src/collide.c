/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:29:49 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:28 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	player_wall(t_v *v, int y_oset, int x_oset)
{
	if (v->map[v->player->y + y_oset][v->player->x + x_oset] == '1')
		return (1);
	return (0);
}

int	player_exit(t_v *v)
{
	if (v->map[v->player->y][v->player->x] == 'E'
		&& v->current_c == v->ini_c)
		return (1);
	return (0);
}

int	player_collect(t_v *v)
{
	if (v->map[v->player->y][v->player->x] == 'C')
	{
		v->current_c += 1;
		v->map[v->player->y][v->player->x] = '0';
		return (1);
	}
	return (0);
}

int	shark_can_move(t_v *v, int i, int y_oset, int x_oset)
{
	const char	*ko;
	char		c;

	ko = "1ES";
	c = v->map[v->shark[i]->y + y_oset][v->shark[i]->x + x_oset];
	if (ft_strchr(ko, c))
		return (1);
	return (0);
}
	