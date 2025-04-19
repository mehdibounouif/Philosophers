/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:45:14 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 09:38:40 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../includes/philo.h"

time_t	current_time(void)
{
	struct	timeval	tv;
	time_t	current;

	gettimeofday(&tv, NULL);
	current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current);
}

void	ft_sleep(t_data *data, time_t time)
{
	time_t	its_time;

	its_time = current_time() + time;
	while (current_time() < its_time)
	{
		if (is_stoped(data))
			break;
		usleep(100);
	}
}

void	ft_wait(time_t start_time)
{
	while (current_time() < start_time)
		continue;
}
