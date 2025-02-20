SRC = parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c main.c \
      ft_itoa.c hb_mtr.c validmap.c validway.c initwind.c moves.c ft_exit.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = so_long

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -Lmlx -lmlx -lXext -lX11 -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
