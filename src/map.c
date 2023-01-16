/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:07:38 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/09 12:38:58 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**get_map(char *map_path)
{
	int			fd;
	char		*nl;
	static char	*map = NULL;
	char		**tmp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	nl = get_next_line(fd);
	if (nl)
		map = ft_strdup("");
	if (!map)
		return (NULL);
	while (nl)
	{
		if (ft_strlen(nl) < 3 || check_char(nl))
			return (NULL);
		map = strj(map, nl);
		if (!map)
			return (NULL);
		nl = get_next_line(fd);
	}
	tmp = ft_split(map, '\n'); //necessaire pour free map avant le retour ft_split(map)
	free(map);
	return (tmp);
}

int	check_map(char **map, t_vars *vars)
{
	int		line_len;
	int		nb_line;

	nb_line = 0;
	line_len = (int) ft_strlen(*map);
	while (map[nb_line])
	{
		if (line_len != (int) ft_strlen(map[nb_line]))
			return (map_error("lines are not the same length"));
		nb_line++;
	}
	vars->map_w = line_len;
	vars->map_h = nb_line;
	if (check_wall(vars) || check_E(vars) || check_C(vars) || check_P(vars))
		return (1);
	return (0);
}

void	print_map(char **map)
{
	    while (*map)
        printf("%s\n", *(map)++);
}

void	free_map(t_vars *vars)
{
	int	y;

	y = -1;
	while (++y < vars->map_h)
		free(vars->map[y]);
	free(vars->map);
}