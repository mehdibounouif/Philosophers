/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:49:16 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 11:16:30 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
static void	output(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", current_time() - philo->data->start,
		philo->id + 1, str);
}

void	write_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (is_stoped(philo->data))
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	if (!ft_strcmp(status, "died"))
		output(philo, "died");
	else if (!ft_strcmp(status, "is eating"))
		output(philo, "is eating");
	else if (!ft_strcmp(status, "is sleeping"))
		output(philo, "is sleeping");
	else if (!ft_strcmp(status,"is thinking"))
		output(philo, "is thinking");
	else if (!ft_strcmp(status, "has taken a fork"))
		output(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->write_lock);
}
