/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:52:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/24 17:59:35 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *s)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - 48);
	while (is_space(*s))
		s++;
	if (*s)
		return (message("Wadakhal number m9ad kon thcham\n"), -1);
	return (res * sign);
}

int	parss_input(int c, char **v)
{
	long			nb;
	int				i;

	i = 1;
	while (i < c)
	{
		nb = ft_atoi(v[i]);
		if (nb == -1)
			return (0);
		if (i == 1 && (nb <= 0 || nb > 200))
		{
			return (message("number of philosophers {0 <= 200}\n"), 0);
		}
		i++;
	}
	return (1);
}
