NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -rf
SRC_DIR = ./src
SRC_FILES = main.c\
	    helper_function.c\
	    init.c\
		free.c\
		modes.c\
		monitor.c\
		output_and_errors.c\
		time_utils.c\
		start_sim.c\



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
