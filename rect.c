/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:12:02 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/03 19:12:57 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_rect(t_rect *rect, int x, int y, int width, int height)
{
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	rect->next = NULL;
}

int	move_rect(int keycode, t_vars *vars)
{
	if (keycode == W)
	{
		vars->rect->y -= STEP;
		vars->rect->height -= STEP;
	}
	if (keycode == A)
	{
		vars->rect->x -= STEP;
		vars->rect->width -= STEP;
	}
	if (keycode == S)
	{
		vars->rect->y += STEP;
		vars->rect->height += STEP;
	}
	if (keycode == D)
	{
		vars->rect->x += STEP;
		vars->rect->width += STEP;
	}
	bg_pix_to_img(vars->img, WHITE);
	rect_pix_to_img(vars->img, *vars->rect, BLUE);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}

int	resize_rect(int keycode, t_vars *vars)
{
	if (keycode == UP)
	{
		vars->rect->height -= STEP;
	}
	if (keycode == LEFT)
	{
		vars->rect->width -= STEP;
	}
	if (keycode == DOWN)
	{
		vars->rect->height += STEP;
	}
	if (keycode == RIGHT)
	{
		vars->rect->width += STEP;
	}
	bg_pix_to_img(vars->img, WHITE);
	rect_pix_to_img(vars->img, *vars->rect, BLUE);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
	return (0);
}

void	draw_rects(t_vars *vars)
{
	t_rect	*tmp;

	tmp = vars->rect;
	while (tmp)
	{
		rect_pix_to_img(vars->img, *tmp, BLUE);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img->img, 0, 0);
}

void	print_rects(t_vars *vars)
{
	t_rect	*tmp;

	tmp = vars->rect;
	while (tmp)
	{
		printf("%p\n", tmp);
//		printf("x:%i\n", tmp->x);
//		printf("y:%i\n", tmp->y);
		tmp = tmp->next;
	}
}