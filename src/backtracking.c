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

int	is_win(char pos)
{
	if (pos == 'E')
	{
		printf("is win\n");
		return (1);
	}
	return (0);
}

int	move(char **map_backtrack, int j, int i)
{
	if (map_backtrack[j][i + 1] != '1' && map_backtrack[j][i + 1] != '2')
	{
		map_backtrack[j][i] = '2';
		return (1);
	}
	else if (map_backtrack[j + 1][i] != '1' && map_backtrack[j + 1][i] != '2')
	{
		map_backtrack[j][i] = '2';
		return (2);
	}
	else if (map_backtrack[j][i - 1] != '1' && map_backtrack[j][i - 1] != '2')
	{
		map_backtrack[j][i] = '2';
		return (3);
	}
	else if (map_backtrack[j - 1][i] != '1' && map_backtrack[j - 1][i] != '2')
	{
		map_backtrack[j][i] = '2';
		return (4);
	}
	else
	{
		map_backtrack[j][i] = '2';
		return (0);
	}
}

int	backtrack(char **map_backtrack, int j, int i, int dep)
{
	if (is_win(map_backtrack[j][i]) == 1)
		return (1);
	dep = move(map_backtrack, j, i);
	if (dep == 1)
	{	
		if (backtrack(map_backtrack, j, i + 1, dep) == 1)
			return (1);
	}
	dep = move(map_backtrack, j, i);
	if (dep == 2)
	{
		if (backtrack(map_backtrack, j + 1, i, dep) == 1)
			return (1);
	}
	dep = move(map_backtrack, j, i);
	if (dep == 3)
	{
		if (backtrack(map_backtrack, j, i - 1, dep) == 1)
			return (1);
	}
	dep = move(map_backtrack, j, i);
	if (dep == 4)
	{
		if (backtrack(map_backtrack, j - 1, i, dep) == 1)
			return (1);
	}
	return (0);
}

/*int	backtrack(char **map_backtrack, int j, int i)
{
	int dep;

	dep = -1;
	if (is_win(map_backtrack[j][i]) == 1)
		return (1);
	dep = move(map_backtrack, j, i);
	printf("j = %d, i = %d\n", j, i);
	if (dep == 0)
		return (0);
	else if (dep == 1)
	{
		backtrack(map_backtrack, j, i + 1);
		return (1);
	}
	else if (dep == 2)
	{
		backtrack(map_backtrack, j + 1, i);
		return (1);
	}
	else if (dep == 3)
	{
		backtrack(map_backtrack, j, i - 1);
		return (1);
	}
	else if (dep == 4)
	{
		backtrack(map_backtrack, j - 1, i);
		return (1);
	}
	else
		return (0);
}*/

/*int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (-1);
	map = get_map(argv[1]);
	ft_printf("%i\n", backtrack(map, 1, 1, -1));
}*/
