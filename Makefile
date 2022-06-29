NAME =		minishell

CFLAGS =	-Wall -Wextra -Werror -I .

SFLAGS =	-fsanitize=address -g

CC =		gcc

LIBSDIR =	libft/

OBJS_DIR = .objs

OBJ =	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

FILES = main.c								\

all: libs $(NAME)

libs:
	$(MAKE) -C $(LIBSDIR)

$(NAME): $(OBJ) $(LIBSDIR)libft.a
	$(CC) $(SFLAG) $(OBJ) $(LIBSDIR)libft.a -o $(NAME)
	
$(OBJS_DIR)/%.o:		%.c minishell.h ${LIBSDIR}libft.h ${LIBSDIR}libft.a Makefile
				mkdir -p $(dir $@)
				${CC} ${CFLAGS} -I$(LIBSDIR) -c $< -o $@

# objs :
# 				mkdir -p $(dir $@)
# 				${CC} ${CFLAGS} -I$(LIBSDIR) -c $< -o $@

clean :
				${MAKE} clean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 

fclean :
				${MAKE} fclean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o
				rm -f ${NAME}
				rm -rf $(OBJS_DIR)

re :			fclean all

.PHONY:			all clean fclean bonus libs re objs