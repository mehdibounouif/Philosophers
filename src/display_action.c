/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:49:16 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 08:00:29 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", current_time() - philo->data->start,
		philo->id + 1, str);
}

void	write_status(t_philo *philo, bool reaper_report, char *status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (is_stoped(philo->data) == true && reaper_report == false)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	if (!ft_strcmp(status, "died"))
		print_status(philo, "died");
	else if (!ft_strcmp(status, "is eating"))
		print_status(philo, "is eating");
	else if (!ft_strcmp(status, "is sleeping"))
		print_status(philo, "is sleeping");
	else if (!ft_strcmp(status,"is thinking"))
		print_status(philo, "is thinking");
	else if (!ft_strcmp(status, "has taken a fork"))
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->write_lock);
}
