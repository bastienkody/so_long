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

#include "../inc/so_long.h"

/* ecrire les erreurs sur la sortie d'erreur */

int	arg_error(int argc, char **argv)
{
	size_t	arg1_len;

	if (argc != 2)
	{
		ft_printf("Error\nYou must only provide one argument : the map path\n");
		return (1);
	}
	arg1_len = ft_strlen(argv[1]);
	if (argv[1][arg1_len - 1] != 'r' || argv[1][arg1_len - 2]
		!= 'e' || argv[1][arg1_len - 3] != 'b' || argv[1][arg1_len - 4] != '.')
	{
		map_error("The map must be *.ber");
		return (1);
	}
	if (arg1_len < 5)
		return (map_error("The map must be <name>.ber"));
	return (0);
}

int	map_error(char *msg)
{
	if (!msg)
		ft_printf("Error\nMap error\n");
	else
		ft_printf("Error\n%s\n", msg);
	return (1);
}
