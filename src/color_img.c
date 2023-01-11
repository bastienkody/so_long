/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:13:45 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/06 14:52:47 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pix_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (color == 0x00FFFF)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	bg_pix_to_img(t_data *img, int color)
{
	int	x;
	int y;

	x = 0;
	while(x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pix_to_img(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	rect_pix_to_img(t_data *img, t_rect *rect, int color)
{
	int	x;
	int y;

	x = rect->x;
	while(x < rect->x + rect->width)
	{
		y = rect->y;
		while (y < rect->y + rect->height)
		{
			ft_printf("rect pix to image fct\n");
			pix_to_img(img, x, y, color);
			ft_printf("x:%i, y:%i\n");
			y++;
		}
		x++;
	}
}
