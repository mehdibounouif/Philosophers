#include "../includes/philo.h"

int	main(int c, char **v)
{
	t_data	*data;
	if (data = malloc(sizeof(t_data)))
                return (1);
	if (c - 1 < 4 || c - 1 > 5)
		message(INPUT_MSG);
	is_valid_input(c, v);
	init(c, v, data);
	exit(EXIT_SUCCESS);
}
