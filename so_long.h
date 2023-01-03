/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:55 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/03 20:00:07 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1920
#define HEIGHT 1080
#define STEP 100

/* keycode */
#define W 119
#define A 97
#define S 115
#define D 100
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

/* mouse button */
#define LEFT_C 1
#define RIGHT_C 2
#define SCROLL 3
#define SCROLL_U 4
#define SCROLL_D 5

/* colors */
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000

/* struct */
typedef struct	s_rect
{
	int x;
	int y;
	int width;
	int height;
	struct s_rect	*next;
}				t_rect;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_rect	*rect;
	t_data	*img;
}				t_vars;

/* prototypes */
void	pix_to_img(t_data *img, int x, int y, int color);
void	bg_pix_to_img(t_data *img, int color);
void	rect_pix_to_img(t_data *img, t_rect rect, int color);
void	init_t_rect(t_rect *rect, int x, int y, int width, int height);
int		move_rect(int keycode, t_vars *vars);
int		resize_rect(int keycode, t_vars *vars);
int		k_inputs(int keycode, t_vars *vars);
int		m_inputs(int button, int x, int y, t_vars *vars);
void	draw_rects(t_vars *vars);
void	print_rects(t_vars *vars);
#endif
