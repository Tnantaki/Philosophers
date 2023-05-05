### Executable ###
NAME	= philo

### Compilation ###
CC		= gcc
RM		= rm -f
C_FLAGS	= -Wall -Wextra -Werror

### Source Files ###
SRCS	= philo.c check_args.c allocate_args.c init_args.c\
			thread.c routine.c timing.c utils.c

### Object Files ###
OBJS	= $(SRCS:.c=.o)

### Rule ###
%.o:%.c
	$(CC) $(C_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
