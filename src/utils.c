#include "../includes/philo.h"

int	is_degit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	is_valid_input(int c, char **v)
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
