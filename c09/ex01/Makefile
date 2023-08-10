SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCL = includes
LFLAGES = -I

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

srcs/%.o : srcs/%.c $(INCL)/ft.h
	$(CC) $(CFLAGS) -c -o $@ $< $(LFLAGES) $(INCL)
	
clean :
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
