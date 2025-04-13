#include "../includes/philo.h"

int	main(int c, char **v)
{
	if (c - 1 < 4 || c - 1 > 5)
		message(INPUT_MSG);
	is_valid_input(c , v);
	exit(EXIT_SUCCESS);
}
