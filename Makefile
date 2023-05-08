# so_long
NAME				=	so_long

SOLONG_SRC			=	src/so_long.c \
						src/get_map.c \
						src/movement.c \
						src/validate_map.c \
						src/utils.c

OBJS				= $(SOLONG_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

# Rules
all:		$(LIBFT) $(NAME)
			@printf "$(BLUE)==> $(CYAN)So_long compiled ✅\n\n$(RESET)"

$(LIBFT):
			@make -C libft bonus

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -Imlx -lmlx -framework OpenGL \
		-framework AppKit $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			@make -C libft fclean
			@$(RM) $(OBJS)
			@printf "\n$(BLUE)==> $(RED)Removed So_long 🗑️\n$(RESET)"

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
			@printf "$(BLUE)==> $(CYAN)So_long recompiled 🔄\n$(RESET)"

.PHONY:		all clean fclean re