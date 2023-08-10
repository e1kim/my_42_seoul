SRCS = main.c ft_atoi.c ft_check_file.c ft_read.c ft_map.c ft_memory.c bsq.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.c ft.h
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean :
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
