/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:52:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 08:40:18 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		message("Wadakha number m9ad kon thcham\n");
	return (res * sign);
}

void	parss_input(int c, char **v)
{
	int	i;
	long	nb;

	i = 1;
	while (i < c)
	{
		nb = ft_atoi(v[i]);
		if ((nb <= 0 || nb > INT_MAX) && i != 5)
			message("");
		i++;
	}
}
