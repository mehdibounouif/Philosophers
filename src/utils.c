#include "../includes/philo.h"

void	is_valid_input(int c, char **v)
{
	int	i;
	long	nb;

	i = 1;
	while (i < c)
	{
		nb = ft_atoi(v[i]);
		if (nb <= 0 || nb > INT_MAX)
			message(RANGE_MSG);
		i++;
	}
}

void	message(char *msg)
{
	printf(msg);
	exit(EXIT_FAILURE);
}
