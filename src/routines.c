/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:12:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 14:17:41 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	write_status(philo, "has taken a fork");
	write_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->meal_time_lock);
	philo_sleep(philo->data, philo->data->time_to_eat);
	//if (is_stoped(philo->data) == false)
	//{
	//	pthread_mutex_lock(&philo->meal_time_lock);
	//	philo->times_ate += 1;
	//	pthread_mutex_unlock(&philo->meal_time_lock);
	//}
	//write_status(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	//philo_sleep(philo->data, philo->data->time_to_sleep);
}

void	sleep_mode(t_philo *philo)
{
	if (is_stoped(philo->data) == false)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, "is sleeping");	
	philo_sleep(philo->data, philo->data->time_to_sleep);
}

void	think_routine(t_philo *philo)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->data->time_to_die
			- (current_time() - philo->last_meal)
			- philo->data->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	write_status(philo, "is thinking");
	philo_sleep(philo->data, time_to_think);
}

void	*single(t_philo *philo)
{
	write_status(philo, "has taken a fork");
	philo_sleep(philo->data, philo->data->time_to_die);
	write_status(philo, "died");
	return (NULL);
}

void	*life_of_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->meal_time_lock);
	wait_others(philo->data->start);
	if (philo->data->time_to_die == 0)
		return (NULL);
	if (philo->data->num_of_philos == 1)
		return (single(philo));
	else if (philo->id % 2)
		think_routine(philo);
	while (is_stoped(philo->data) == false)
	{
		eat_sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
