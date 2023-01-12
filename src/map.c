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
	int		fd;
	char	*nl;
	char	*map;
	char	**tmp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("err on map opening with path %s\n", map_path);
		return (NULL);
	}
	nl = get_next_line(fd);
	map = NULL;
	if (nl)
		map = ft_strdup("");
	if (!map)
		return (NULL);
	while (nl)
	{
		map = strj(map, nl);
		if (!map)
			return (NULL);
		nl = get_next_line(fd);
	}
	tmp = ft_split(map, '\n'); //necessaire pour free map avant le retour ft_split(map)
	free(map);
	return (tmp);
}

int	check_wall(char **map, int nb_line, int line_len)
{
	int	i;

	i = -1;
	while (++i < line_len)
	{
		if (map[0][i] != '1')
			return (map_error("not complety walled on first line"));
		if (map[nb_line -1][i] != '1')
			return (map_error("not complety walled on last line"));
	}
	i = -1;
	while (++i < nb_line)
	{
		if (map[i][0] != '1')
			return (map_error("not complety walled on left side"));
		if (map[i][line_len- 1] != '1')
			return (map_error("not complety walled on right side"));
	}
	return (0);
}

int	check_elem(char **map, int nb_line)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	while (nb_line-- > 0)
	{
		if (ft_strchr((const char *) map[nb_line], 'C'))
			c += 1;
		if (ft_strchr((const char *) map[nb_line], 'P'))
		{
			p+= 1;
			if (p > 1 || (ft_strrchr((const char *) map[nb_line], 'P')  && ft_strchr((const char *) map[nb_line], 'P') != ft_strrchr((const char *) map[nb_line], 'P')))
				return (map_error("map error : more tham one player start pos"));
		}
		if (ft_strchr((const char *) map[nb_line], 'E'))
		{
			e+= 1;
			if (e > 1 || (ft_strrchr((const char *) map[nb_line], 'E')  && ft_strchr((const char *) map[nb_line], 'E') != ft_strrchr((const char *) map[nb_line], 'E')))
				return (map_error("map error : more tham one exit"));
		}
	}
	if (!c || !p || !e)
		return (map_error("map error : missing collectible or player start or exit"));
	return (0);
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
	if (check_elem(map, nb_line))
		return (1);
	return (check_wall(map, nb_line, line_len));
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