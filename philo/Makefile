### Executable ###
NAME	= philo

### Compilation ###
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -pthread -fsanitize=address -g

### Source Files ###
SRCS	= philo.c check_args.c allocate_args.c init_args.c\
			thread.c routine.c timing.c utils.c

### Object Files ###
OBJS	= $(SRCS:.c=.o)

### Compilation Rules ###
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
