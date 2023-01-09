SRC_DIR = ./src/

SRCS = ${SRC_DIR}main.c\
		${SRC_DIR}color_img.c\
		${SRC_DIR}player.c\
		${SRC_DIR}tileset.c\
		${SRC_DIR}rect.c\
		${SRC_DIR}draw.c\
		${SRC_DIR}map.c\
		${SRC_DIR}print_error.c\

OBJS =	${SRCS:.c=.o}

NAME =	so_long

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -g3

LDFLAGS =	-lXext -lX11 -lm -L./mlx -lmlx_Linux -L./libft -lft 

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

