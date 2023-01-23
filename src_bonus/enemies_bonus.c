/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:27:24 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/17 17:30:07 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_enemies_from_map(t_v *v)
{
	char	*tmp;
	int		i;

	i = v->map_h;
	while (i-- > 0)
	{
		tmp = ft_strchr((const char *) v->map[i], 'S');
		while (tmp)
		{
			v->nb_enemies += 1;
			tmp++;
			tmp = ft_strchr((const char *) tmp, 'S');
		}
	}
	if (!v->nb_enemies)
		return (1);
	return (0);
}

int	move_shark(t_v *v, int i)
{
	v->shark[i]->moves += 1;
	if (shark_can_move(v, i, 1, 0) && shark_can_move(v, i, -1, 0)
		&& shark_can_move(v, i, 0, -1) && shark_can_move(v, i, 0, 1))
		return (0);
	if (v->shark[i]->y < v->player->y)
		v->shark[i]->dir = 'D';
	else if (v->shark[i]->y > v->player->y)
		v->shark[i]->dir = 'U';
	else if (v->shark[i]->x > v->player->x)
		v->shark[i]->dir = 'L';
	else if (v->shark[i]->x < v->player->x)
		v->shark[i]->dir = 'R';
	if (v->shark[i]->y < v->player->y && !shark_can_move(v, i, 1, 0))
		v->shark[i]->y += 1;
	else if (v->shark[i]->y > v->player->y && !shark_can_move(v, i, -1, 0))
		v->shark[i]->y -= 1;
	else if (v->shark[i]->x > v->player->x && !shark_can_move(v, i, 0, -1))
		v->shark[i]->x -= 1;
	else if (v->shark[i]->x < v->player->x && !shark_can_move(v, i, 0, 1))
		v->shark[i]->x += 1;
	return (1);
}

void	draw_shark(t_v *v, int i)
{
	int	x;
	int	y;
	int	moves;

	if (!v->shark || !v->shark[i] || !v->shark[i]->is_alive)
		return ;
	x = v->shark[i]->x * STEP;
	y = v->shark[i]->y * STEP;
	moves = v->shark[i]->moves;
	if (v->shark[i]->dir == 'L')
		mlx_put_image_to_window(v->ptr, v->win,
			v->shark[i]->pos_l[moves % 4]->img, x, y);
	else if (v->shark[i]->dir == 'R')
		mlx_put_image_to_window(v->ptr, v->win,
			v->shark[i]->pos_r[moves % 4]->img, x, y);
	else if (v->shark[i]->dir == 'U')
		mlx_put_image_to_window(v->ptr, v->win,
			v->shark[i]->pos_u[moves % 4]->img, x, y);
	else if (v->shark[i]->dir == 'D')
		mlx_put_image_to_window(v->ptr, v->win,
			v->shark[i]->pos_d[moves % 4]->img, x, y);
}

void	print_shark(t_v *v)
{
	int	nb;

	nb = v->nb_enemies;
	while (--nb > -1)
	{
		ft_fprintf(2, "shark%i: dir =%c, x=%i, y=%i\n", nb, v->shark[nb]->dir,
			v->shark[nb]->x, v->shark[nb]->y);
	}
}
