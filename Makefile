SRCS = 	main.c\
		color_img.c\
		player.c\
		tileset.c\
		rect.c\
		draw.c\
		map.c\
		print_error.c\

OBJS =	${SRCS:.c=.o}

NAME =	so_long

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

LDFLAGS =	-lXext -lX11 -lm -L./mlx -lmlx -L./libft -lft

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	libft mlx ${OBJS}
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS} 

all:		${NAME}

exec:		${NAME}
		./${NAME}

libft:
		make -C libft/

mlx:
		make -C mlx/

clean:
		rm -rf ${OBJS}
		make clean -C libft/

fclean:		clean
		rm -rf ${NAME}
		make fclean -C libft/

re:		fclean all

.PHONY:	all clean fclean re libft mlx

