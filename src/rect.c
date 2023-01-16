/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:12:02 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/05 13:07:45 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_rect	*init_t_rect(int x, int y, int width, int height)
{
	t_rect	*rect;

	rect = malloc(sizeof(rect));
	if (!rect)
		return (NULL);
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	return (rect);
}

int	move_rect(int keycode, t_v *v)
{
	if (keycode == W)
	{
		v->rect->y -= STEP;
	}
	if (keycode == A)
	{
		v->rect->x -= STEP;
	}
	if (keycode == S)
	{
		v->rect->y += STEP;
	}
	if (keycode == D)
	{
		v->rect->x += STEP;
	}
	return (0);
}

int	resize_rect(int keycode, t_v *v)
{
	if (keycode == UP)
	{
		v->rect->height -= STEP;
	}
	if (keycode == LEFT)
	{
		v->rect->width -= STEP;
	}
	if (keycode == DOWN)
	{
		v->rect->height += STEP;
	}
	if (keycode == RIGHT)
	{
		v->rect->width += STEP;
	}
	return (0);
}

/*void	draw_rects(t_v *v)
{
	t_rect	*tmp;

	tmp = v->rect;
	while (tmp)
	{
		rect_pix_to_img(v->img, tmp, BLUE);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(v->mlx_ptr, v->mlx_win, v->img->img, 0, 0);
}

void	print_rects(t_v *v)
{
	t_rect	*tmp;

	tmp = v->rect;
	if (!tmp)
		printf("prit_rect : no rect");
	while (tmp)
	{
		printf("%p\n", tmp);
		printf("x:%i\n", tmp->x);
		printf("y:%i\n", tmp->y);
		tmp = tmp->next;
	}
}*/
