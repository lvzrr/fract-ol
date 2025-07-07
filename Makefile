NAME		:=	fract-ol
SRCDIR		:=	src
SRC			:=	$(wildcard $(SRCDIR)/*.c)
INCLUDEF	:=	-I./include -I./libft/include -I./minilibx-linux
LIB			:=	libft/libft.a minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a
BUILDDIR	:= build
OBJ			:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))
CC			:= cc
CFLAGS  	:= -Wall -Wextra -Werror $(INCLUDEF)
LDFLAGS		:= $(LIB) -lX11 -lbsd -lXext

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	@$(MAKE) -C libft
	@$(MAKE) -C	minilibx-linux

clean:
	@rm -rf $(BUILDDIR)
	@$(MAKE) -C libft clean
	@$(MAKE) -C minilibx-linux clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re
MAKEFLAGS += --no-print-directory
