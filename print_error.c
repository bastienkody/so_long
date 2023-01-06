/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:58 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 18:40:55 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_error(void)
{
	ft_printf("you must give only one argument : the map path\n");
	return (1);
}

int	map_error(char *msg)
{
	if (!msg)
		ft_printf("map error\n");
	else
		ft_printf("%s\n", msg);
	return (1);
}
