/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:29:49 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/16 16:11:05 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_char(char *line)
{
	const char	*valid_char;

	valid_char = "01PEC\n";
	while (*line)
	{
		if (!ft_strchr(valid_char, *line++))
			return (map_error("Unrecognized character"));
	}
	return (0);
}

int	check_wall(t_v *v)
{
	int	i;

	i = -1;
	while (++i < v->map_w)
	{
		if (v->map[0][i] != '1')
			return (map_error("Map not complety walled on first line"));
		if (v->map[v->map_h - 1][i] != '1')
			return (map_error("Map not complety walled on last line"));
	}
	i = -1;
	while (++i < v->map_h)
	{
		if (v->map[i][0] != '1')
			return (map_error("Map not complety walled on left side"));
		if (v->map[i][v->map_w - 1] != '1')
			return (map_error("Map not complety walled on right side"));
	}
	return (0);
}

int	check_c(t_v *v)
{
	char	*tmp;
	int		i;

	i = v->map_h;
	while (i-- > 0)
	{
		tmp = ft_strchr((const char *) v->map[i], 'C');
		while (tmp)
		{
			v->ini_c += 1;
			tmp++;
			tmp = ft_strchr((const char *) tmp, 'C');
		}
	}
	if (!v->ini_c)
		return (map_error("Missing collectible"));
	return (0);
}

int	check_p(t_v *v)
{
	char	*tmp;
	int		i;
	int		p;

	i = v->map_h;
	p = 0;
	while (i-- > 0)
	{
		tmp = ft_strchr((const char *) v->map[i], 'P');
		while (tmp)
		{
			p += 1;
			tmp++;
			tmp = ft_strchr((const char *) tmp, 'P');
		}
	}
	if (p != 1)
		return (map_error("You must provide exactly one player start pos"));
	return (0);
}

int	check_e(t_v *v)
{
	char	*tmp;
	int		i;
	int		e;

	i = v->map_h;
	e = 0;
	while (i-- > 0)
	{
		tmp = ft_strchr((const char *) v->map[i], 'E');
		while (tmp)
		{
			e += 1;
			tmp++;
			tmp = ft_strchr((const char *) tmp, 'E');
		}
	}
	if (e != 1)
		return (map_error("You must provide exactly one exit pos"));
	return (0);
}
