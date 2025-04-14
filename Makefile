NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf
SRC_DIR = ./src
SRC_FILES = main.c\
	    utils.c\
	    helper_function.c\
	    init.c\


SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.c: %.o
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all
