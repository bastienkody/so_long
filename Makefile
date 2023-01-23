SRC_DIR = ./src/

BNSRC_DIR = ./src_bonus/

SRCS =	${SRC_DIR}main.c\
		${SRC_DIR}backtracking.c\
		${SRC_DIR}player.c\
		${SRC_DIR}tileset.c\
		${SRC_DIR}draw.c\
		${SRC_DIR}map.c\
		${SRC_DIR}print_error.c\
		${SRC_DIR}collide.c\
		${SRC_DIR}update.c\
		${SRC_DIR}checker.c\
		${SRC_DIR}enemies.c\
		${SRC_DIR}enemies_loading.c

BNSRCS =	${BNSRC_DIR}main_bonus.c\
		${BNSRC_DIR}backtracking_bonus.c\
		${BNSRC_DIR}player_bonus.c\
		${BNSRC_DIR}tileset_bonus.c\
		${BNSRC_DIR}draw_bonus.c\
		${BNSRC_DIR}map_bonus.c\
		${BNSRC_DIR}print_error_bonus.c\
		${BNSRC_DIR}collide_bonus.c\
		${BNSRC_DIR}update_bonus.c\
		${BNSRC_DIR}checker_bonus.c\
		${BNSRC_DIR}enemies_bonus.c\
		${BNSRC_DIR}enemies_loading_bonus.c

OBJS =	${SRCS:.c=.o}

BNOBJS =	${BNSRCS:.c=.o}

NAME =	so_long

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

LDFLAGS =	-lXext -lX11 -L./mlx -lmlx -L./libft -lft 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	libft mlx ${OBJS}
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

bonus:		libft mlx ${BNOBJS}
			${CC} -o ${NAME} ${BNOBJS} ${LDFLAGS} 

all:		${NAME}

libft:
		make -C libft/

mlx:
		make -C mlx/

clean:
		rm -rf ${OBJS}
		make clean -C libft/

cleanbonus:
		rm -rf ${BNOBJS}
		make clean -C libft/

fclean:		clean
		rm -rf ${NAME}
		make fclean -C libft/

fcleanbonus:	cleanbonus
			rm -rf ${NAME}
			make fclean -C libft/


re:		fclean all

rebonus:		fcleanbonus bonus

.PHONY:	all clean cleanbonus fclean fcleanbonus re rebonus libft mlx

