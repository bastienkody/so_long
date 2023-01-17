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

char	**err_on_read(char *map, char *nl)
{
	if (ft_strlen(nl) < 4)
		ft_printf("Line lenght is lower than 3 (line feed excluded)\n");
	free(map);
	free(nl);
	return (NULL);
}

 /* tmp necessaire pour free map avant le retour ft_split(map) */
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
		if (ft_strlen(nl) < 4 || check_char(nl))
			return (err_on_read(map, nl));
		map = strj(map, nl);
		if (!map)
			return (NULL);
		nl = get_next_line(fd);
	}
	tmp = ft_split(map, '\n');
	free(map);
	return (tmp);
}

int	check_map(char **map, t_v *v)
{
	int		line_len;
	int		nb_line;

	nb_line = 0;
	line_len = (int) ft_strlen(*map);
	while (map[nb_line])
	{
		if (line_len != (int) ft_strlen(map[nb_line]))
			return (map_error("Lines are not the same length"));
		nb_line++;
	}
	v->map_w = line_len;
	v->map_h = nb_line;
	if (check_wall(v) || check_e(v) || check_c(v) || check_p(v))
		return (1);
	return (0);
}

void	print_map(char **map)
{
	while (*map)
		printf("%s\n", *(map)++);
}

void	free_map(t_v *v)
{
	int	y;

	y = -1;
	while (++y < v->map_h)
		free(v->map[y]);
	free(v->map);
}
