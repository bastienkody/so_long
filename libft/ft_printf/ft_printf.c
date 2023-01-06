/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:09:34 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 16:14:55 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	format(const char *str, int i, va_list init)
{
	int	len;

	len = 0;
	if (str[i + 1] == 'c')
		len = print_char(init);
	if (str[i + 1] == '%')
		len = write(STD_OUT, "%", 1);
	if (str[i + 1] == 's')
		len = print_str(init);
	if (str[i + 1] == 'p')
		len = print_ptr(init);
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len = print_deci(init);
	if (str[i + 1] == 'x')
		len = print_hexa(init, 'x');
	if (str[i + 1] == 'X')
		len = print_hexa(init, 'X');
	if (str[i + 1] == 'u')
		len = print_unsigned(init);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	init;
	int		i;
	int		len;

	va_start(init, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			len += write(STD_OUT, &str[i++], 1);
		if (str[i] && str[i] == '%')
		{
			len += format(str, i, init);
			i += 2;
		}
	}
	va_end(init);
	return (len);
}
