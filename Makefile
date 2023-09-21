LIB_LINUX	= -lm -lbsd -lX11 -lXext
LIB_MAC		= -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB			= $(LIB_LINUX)

NAME		= cell_simulation

SRC_DIR		= .
SRCS		= $(patsubst %, $(SRC_DIR)/%, main.c color.c key_hook.c drawing.c \
				maths.c divers.c mouse_hook.c simulation.c update_img.c)

OBJ_DIR		= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS		= minilibx-linux/libmlx_Linux.a

CC			= cc
CFLAGS		= -g -Ofast #-Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I minilibx-linux -c $< -o $@

$(NAME):	$(OBJS)
			@make -C minilibx-linux
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@ -L ./libft $(LIB)
			@echo "Done"

all:		$(NAME)

clean:
#			@make clean -C minilibx-linux
			@$(RM) $(OBJS)
			@echo "Remove obj"

fclean:		clean
#			@make clean -C minilibx-linux
			@$(RM) $(NAME)
			@echo "Remove $(NAME)"

re:			fclean all

.PHONY:		all clean fclean re