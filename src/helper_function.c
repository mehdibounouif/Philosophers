#include "../includes/philo.h"

int	ft_atoi(char *s)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		res += *s - 48;
		s++;
	}
	while (*s == 32)
		s++;
	if (*s)
		message(NUMBER_MSG);
	return (res * sign);
}
