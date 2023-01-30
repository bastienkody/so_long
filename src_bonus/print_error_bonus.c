/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:58 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/11 17:25:31 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	arg_error(int argc, char **argv)
{
	size_t	arg1_len;
	char	*tmp;

	if (argc != 2)
	{
		ft_fprintf(2, "Error\nYou must (only) provide 1 arg : map path\n");
		return (1);
	}
	tmp = argv[1];
	if (ft_strrchr(argv[1], '/'))
		tmp = ft_strrchr(argv[1], '/') + 1;
	arg1_len = ft_strlen(tmp);
	if (arg1_len < 5)
		return (map_error("The map must be <name>.ber"));
	if (tmp[arg1_len - 1] != 'r' || tmp[arg1_len - 2]
		!= 'e' || tmp[arg1_len - 3] != 'b' || tmp[arg1_len - 4] != '.')
		map_error("The map must be <name>.ber");
	return (0);
}

int	map_error(char *msg)
{
	if (!msg)
		ft_fprintf(2, "Error\nMap error\n");
	else
		ft_fprintf(2, "Error\n%s\n", msg);
	return (1);
}
