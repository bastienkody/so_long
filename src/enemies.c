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

/* ajouter recup des pos x,y aussi en + du nb */
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

void	get_shark_pos(t_v *v)
{
	int	nb;
	int	y;
	int	x;

	nb = v->nb_enemies - 1;
	y = -1;
	while (++y < v->map_h)
	{
		x = -1;
		while (++x < v->map_w)
		{
			if (v->map[y][x] == 'S')
			{
				v->shark[nb]->x = x;
				v->shark[nb--]->y = y;
			}
		}
	}
}

int	check_load_shark(t_v *v)
{
	int	nb;
	int	i;

	nb = v->nb_enemies;
	while (--nb > -1)
	{
		i = -1;
		while (++i < 4)
		{
			if (!v->shark[nb]->pos_l[i] || !v->shark[nb]->pos_r[i]
				|| !v->shark[nb]->pos_u[i] || !v->shark[nb]->pos_d[i])
				return (1);
		}
	}
	return (0);
}

t_player	*load_shark(t_v *v)
{
	t_player	*shark;

	shark = malloc(1 * sizeof(t_player));
	if (!shark)
		return (NULL);
	shark->pos_l[0] = init_tile(v, S_L_1);
	shark->pos_l[1] = init_tile(v, S_L_2);
	shark->pos_l[2] = init_tile(v, S_L_3);
	shark->pos_l[3] = init_tile(v, S_L_4);
	shark->pos_r[0] = init_tile(v, S_R_1);
	shark->pos_r[1] = init_tile(v, S_R_2);
	shark->pos_r[2] = init_tile(v, S_R_3);
	shark->pos_r[3] = init_tile(v, S_R_4);
	shark->pos_u[0] = init_tile(v, S_U_1);
	shark->pos_u[1] = init_tile(v, S_U_2);
	shark->pos_u[2] = init_tile(v, S_U_3);
	shark->pos_u[3] = init_tile(v, S_U_4);
	shark->pos_d[0] = init_tile(v, S_D_1);
	shark->pos_d[1] = init_tile(v, S_D_2);
	shark->pos_d[2] = init_tile(v, S_D_3);
	shark->pos_d[3] = init_tile(v, S_D_4);
	return (shark);
}

int	init_sharks(t_v *v)
{
	t_player	**sharks;
	int			nb;

	nb = v->nb_enemies;
	ft_printf("enemies nb:%i\n", nb);
	sharks = malloc(nb * sizeof(t_player));
	if (!sharks)
		return (1);
	while (--nb > -1)
		sharks[nb] = load_shark(v);
	v->shark = sharks;
	get_shark_pos(v);
	if (check_load_shark(v))
		return (1);
	return 0;
}

/*void	unload_shark(t_v *v)
{
	int	i;

	i = -1;
	if (!v->shark)
		return ;
	while (++i < 4)
	{
		if (v->shark->pos_r[i] && v->shark->pos_r[i]->img)
			mlx_destroy_image(v->ptr, v->shark->pos_r[i]->img);
		if (v->shark->pos_l[i] && v->shark->pos_l[i]->img)
			mlx_destroy_image(v->ptr, v->shark->pos_l[i]->img);
		if (v->shark->pos_u[i] && v->shark->pos_u[i]->img)
			mlx_destroy_image(v->ptr, v->shark->pos_u[i]->img);
		if (v->shark->pos_d[i] && v->shark->pos_d[i]->img)
			mlx_destroy_image(v->ptr, v->shark->pos_d[i]->img);
		if (v->shark->pos_r[i])
			free(v->shark->pos_r[i]);
		if (v->shark->pos_l[i])
			free(v->shark->pos_l[i]);
		if (v->shark->pos_u[i])
			free(v->shark->pos_u[i]);
		if (v->shark->pos_d[i])
			free(v->shark->pos_d[i]);
	}
	free(v->player);
}*/




void	print_shark(t_v *v)
{
	int	nb;

	nb = v->nb_enemies;
	while (--nb > -1)
	{
		ft_printf("shark%i: x=%i, y=%i\n", nb, v->shark[nb]->x, v->shark[nb]->y);
	}
}