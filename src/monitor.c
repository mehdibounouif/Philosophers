/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:46:40 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 11:31:02 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	set_sim_stop_flag(t_data *data, int state)
// {
// 	pthread_mutex_lock(&data->sim_stop_lock);
// 		data->stop_flag = state;
// 	pthread_mutex_unlock(&data->sim_stop_lock);
// }

int	is_stoped(t_data *data)
{
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->stop_flag == 1)
	{
		pthread_mutex_unlock(&data->sim_stop_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (0);
}

int	is_kill(t_philo *philo)
{
	if ((current_time() - philo->last_meal) >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->sim_stop_lock);
		philo->data->stop_flag = 1;
    pthread_mutex_unlock(&philo->data->sim_stop_lock);
		write_status(philo, "died");
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (1);
	}
	return (0);
}

int	philo_state(t_data *data)
{
	unsigned int	i;
	int			eat_enough;

	eat_enough = 1;
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_time_lock);
		if (is_kill(data->philos[i]))
			return (true);
		if (data->num_of_meals != -1)
			if (data->philos[i]->times_ate < (unsigned int)data->num_of_meals)
				eat_enough = 0;
		pthread_mutex_unlock(&data->philos[i]->meal_time_lock);
		i++;
	}
	if (data->num_of_meals != -1 && eat_enough == 1)
	{
		pthread_mutex_lock(&data->sim_stop_lock);
		data->stop_flag = 1;
	  pthread_mutex_unlock(&data->sim_stop_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *args)
{
	t_data			*data;

	data = (t_data *)args;
	pthread_mutex_lock(&data->sim_stop_lock);
		data->stop_flag = 0;
	pthread_mutex_unlock(&data->sim_stop_lock);
	wait_others(data->start);
	while (true)
	{
		if (philo_state(data) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
