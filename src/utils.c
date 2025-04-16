#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
