NAME = philo

SRCS = philo.c init.c routine.c monitor.c utils.c
OBJS = $(SRCS:.c=.o)

CC = CC
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o: %.c philo.h
		$(CC) $(OBJS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
