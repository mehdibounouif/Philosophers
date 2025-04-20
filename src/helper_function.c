/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:29:22 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/20 15:15:59 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_sim_stop_flag(t_data *data,  int status)
{
	pthread_mutex_lock(&data->sim_stop_lock);
	data->sim_stop = status;
	pthread_mutex_unlock(&data->sim_stop_lock);
}

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


