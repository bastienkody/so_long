/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:13:45 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/03 19:16:23 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pix_to_img(t_data *img, int x, int y, int color)
{
	char	*dst;

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

void	rect_pix_to_img(t_data *img, t_rect rect, int color)
{
	int y;

	while(rect.x < rect.width)
	{
		y = rect.y;
		while (y < rect.height)
		{
			pix_to_img(img, rect.x, y, color);
			y++;
		}
		rect.x++;
	}
}
