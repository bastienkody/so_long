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

int	backtrack(char **map, int y, int x)
{
	t_moves	moves;

	//ft_printf("y=%i, x=%i\n", y, x);
	if (map[y][x] == 'E')
		return (1);
	can_move(&moves, map, y, x);
	if (moves.right && backtrack(map, y, x + 1))
		return (1);
	if (moves.down && backtrack(map, y + 1, x))
		return (1);
	if (moves.left && backtrack(map, y, x - 1))
		return (1);
	if (moves.up && backtrack(map, y - 1, x))
		return (1);
	return (0);
}

// 6 * 10
int	main(int argc, char **argv)
{
	char	**map;
	int		x;
	int 	y;

	if (argc != 2)
		return (-1);
	map = get_map(argv[1]);
	x = -1;
	while (++x < 10)
	{
		y = -1;
		while (++y < 6)
		{
			if (map[y][x] == 'P')
				ft_printf("%i\n", backtrack(map, y, x));
		}	
	}
}
