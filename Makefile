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
	@echo "🎉 Linking object files to create the executable: $(NAME) 🚀"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "✅ Build successful! Executable created: $(NAME)"

%.o: %.c
	@echo "🔨 Compiling ..."
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "✅ compiled successfully!"

clean:
	@echo "🧹 Cleaning up object files ..."
	@$(RM) $(OBJS)
	@echo "✅ Clean up complete."

fclean: clean
	@echo "🧹 Cleaning up object files and executable..."
	@$(RM) $(NAME)
	@echo "✅ Clean up complete."

re: fclean all

.SECONDARY : $(OBJS)

.PHONY: re clean fclean all
