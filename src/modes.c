/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:41:53 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 10:42:30 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleep_mode(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks_locks[philo->fork[0]]);
	display(philo, "has taken a fork");
	display(philo, "has taken a fork");
	display(philo, "is eating");
	philo->last_meal = current_time();
	philo_sleep(philo->data, philo->data->time_to_eat);
	if (!has_simulation_stopped(philo->data))
		philo->time_ate ++;
	display(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->forks_locks[philo->fork[0]]);
	philo_sleep(philo->data, philo->data->time_to_sleep);
}

void	think_mode(t_philo *philo, int	flag)
{
	time_t	thinking_time;

	pthread_mutex_lock(&philo->meal_time_lock);
	thinking_time = (philo->data->time_to_die -
			(current_time() - philo->last_meal) -
			philo->data->time_to_eat) / 2;
	pthread_mutex_lock(&philo->meal_time_lock);
	if (thinking_time < 0)
		thinking_time = 0;
	if (thinking_time < 0 && flag == 1)
		thinking_time = 1;
	if (thinking_time > 600)
		thinking_time = 200;
	philo_sleep(philo->data, thinking_time);
}
