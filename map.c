/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:07:38 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 20:28:44 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *map_path)
{
	int		fd;
	char	*nl;
	char	*map;

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
	return (ft_split(map, '\n'));
}

/*int	main(void)
{
	char	**split;

	split = get_map("Makefile");
	while (*split)
		ft_printf("%s\n", *split++);
}*/

/* check for rectangle form + encadrer de murs 
return 1 on error, 0 on success*/
int	check_map(char **map)
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
	return (check_wall(map, nb_line, line_len));
}

int	check_wall(char **map, int nb_line, int line_len)
{
	int	i;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != '1')
			return (map_error("not complety walled on left side"));
	}
	i = -1;
	while (map[line_len -1][++i])
	{
		if (map[line_len -1][i] != '1')
			return (map_error("not complety walled on right side"));
	}
	i = -1;
	while (map[++i][0])
	{
		if (map[i][0] != '1')
			return (map_error("not complety walled on first line"));
	}
	i = -1;
	while (map[++i][nb_line -1])
	{
		if (map[i][nb_line -1] != '1')
			return (map_error("not complety walled on last line"));
	}
	return (0);
}

void	print_map(char **map)
{
	    while (*map)
        printf("%s\n", *(map)++);
}
