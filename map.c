/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:07:38 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 18:09:43 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *map_path)
{
	int		fd;
	char	*nl;
	int		line_len;
	char	*map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("err on map opening with path %s\n", map_path);
		return (NULL);
	}
	nl = get_next_line(fd);
	line_len = (int) ft_strlen(nl);
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

/* check for rectangle form + encadrer de murs */
int	check_map(char **map)
{
	char	**tmp;
	int		line_len;
	int		nb_line;

	tmp = map;
	nb_line = 0;
	while (*tmp++)
		nb_line++;
}
