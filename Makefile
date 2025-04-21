NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -rf
SRC_DIR = ./src
SRC_FILES =	philo.c \
			start.c \
			stop.c \
			parsing.c \
			monitor.c \
			time.c \
			routines.c \
			ft_init.c \
			display_action.c \
			utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all
