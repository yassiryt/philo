SRC =	basic_func.c\
		log_func.c\
		err_func.c\
		init_func.c\
		monitor_func.c\
		parcing_func.c\
		routine_func.c\
		thread_func.c\
		time_func.c\
		rand_func.c\
		main.c

OBJS = $(SRC:.c=.o)

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADERS = philo.h

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
