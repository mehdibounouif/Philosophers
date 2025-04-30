/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:46:40 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/30 08:43:12 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_stoped(t_data *data)
{
	pthread_mutex_lock(&data->stop_lock);
	if (data->stop_flag == 1)
	{
		pthread_mutex_unlock(&data->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->stop_lock);
	return (0);
}

int	is_kill(t_philo *philo)
{
	if ((current_time() - philo->last_meal) >= philo->data->time_to_die)
	{
		write_status(philo, "died");
		pthread_mutex_lock(&philo->data->stop_lock);
		philo->data->stop_flag = 1;
		pthread_mutex_unlock(&philo->data->stop_lock);
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	return (0);
}

int	philo_state(t_data *data)
{
	int	i;
	int	eat_enough;

	eat_enough = 1;
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (is_kill(&data->philos[i]))
			return (1);
		if (data->num_of_meals != -1)
			if (data->philos[i].count_meals >= data->num_of_meals)
				eat_enough++;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	if (data->num_of_meals != -1 && eat_enough > data->num_of_philos)
	{
		pthread_mutex_lock(&data->stop_lock);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->stop_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *args)
{
	t_data			*data;

	data = (t_data *)args;
	wait_others(data->start);
	while (1)
	{
		if (philo_state(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
