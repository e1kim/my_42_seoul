SRCS = main.c ft_atoi.c ft_putnbr.c ft_calculator.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
