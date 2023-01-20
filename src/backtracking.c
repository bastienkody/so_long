/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:23:43 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/12 14:14:40 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

typedef struct	s_moves
{
	int	left;
	int	right;
	int	up;
	int	down;
}				t_moves;

void	can_move(t_moves *moves, char **map, int y, int x)
{
	moves->right = 0;
	moves->down = 0;
	moves->left = 0;
	moves->up = 0;
	if (map[y][x + 1] != '1')
		moves->right = 1;
	if (map[y + 1][x] != '1')
		moves->down = 1;
	if (map[y][x - 1] != '1')
		moves->left = 1;
	if (map[y - 1][x] != '1')
		moves->up = 1;
	map[y][x] = '1';
}

int	backtrack(char **map, char search, int y, int x)
{
	t_moves	moves;

	//ft_printf("y=%i, x=%i\n", y, x);
	if (map[y][x] == search)
		return (1);
	can_move(&moves, map, y, x);
	if (moves.right && backtrack(map, search, y, x + 1))
		return (1);
	if (moves.down && backtrack(map, search, y + 1, x))
		return (1);
	if (moves.left && backtrack(map, search,  y, x - 1))
		return (1);
	if (moves.up && backtrack(map, search, y - 1, x))
		return (1);
	return (0);
}

int	backtrack_launch(t_v *v)
{
	char	**map;
	int		x;
	int 	y;

	map = v->map;
	x = -1;
	while (++x < v->map_w)
	{
		y = -1;
		while (++y < v->map_h)
		{
			if (map[y][x] == 'P')
				ft_printf("%i\n", backtrack(map, 'E', y, x));
			if (map[y][x] == 'C')
				ft_printf("%i\n", backtrack(map, 'P', y, x)); // add 4th parameter to backtrack??

		}	
	}
}
