/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:55:10 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/25 07:49:00 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_sleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up_time;

	wake_up_time = current_time() + sleep_time;
	while (current_time() < wake_up_time)
	{
		if (is_stoped(data))
			break ;
		usleep(1000);
	}
}

void	wait_others(time_t start)
{
	while (current_time() < start)
		continue ;
}
