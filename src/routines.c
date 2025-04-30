/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:12:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/30 08:46:31 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	write_status(philo, "has taken a fork");
	write_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	philo_sleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	if (!is_stoped(philo->data))
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->count_meals += 1;
		pthread_mutex_unlock(&philo->meal_lock);
	}
}

void	sleep_routine(t_philo *philo)
{
	write_status(philo, "is sleeping");
	philo_sleep(philo->data, philo->data->time_to_sleep);
}

void	think_routine(t_philo *philo)
{
	time_t	thinkign_time;
	time_t	hangry;
	time_t	left_until_death;

	pthread_mutex_lock(&philo->meal_lock);
	hangry = current_time() - philo->last_meal;
	left_until_death = philo->data->time_to_die - hangry;
	thinkign_time = (left_until_death - philo->data->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_lock);
	if (thinkign_time < 0)
		thinkign_time = 0;
	write_status(philo, "is thinking");
	philo_sleep(philo->data, thinkign_time);
}

void	*single_routine(t_philo *philo)
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
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->meal_lock);
	wait_others(philo->data->start);
	if (philo->data->num_of_philos == 1)
		return (single_routine(philo));
	else if (philo->id % 2)
		think_routine(philo);
	while (!is_stoped(philo->data))
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
