NAME	:= so_long

CC	:= gcc

CFLAGS	:= -Wall -Wextra -Werror -Iheaders/

MXFLAGS	:= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SOURCE	:= game_functions/*.c

GNL	:= get_next_line/*.c

LIBFT	:= libft/*.c

PRINTF	:= ft_printf/*.c

MLIBX	:= minilibx-linux/

all:
	make -C $(MLIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GNL) $(LIBFT) $(PRINTF) $(MXFLAGS) -o $(NAME)

clean:
	make clean -C $(MLIBX)
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

