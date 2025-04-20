/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:09:42 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/20 15:22:48 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	kill_philo(t_philo *philo)
{
	if ((current_time() - philo->last_meal) >= philo->data->time_to_die)
	{
		set_sim_stop_flag(philo->data, 1);
		display(philo, "died");
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (1);
	}
	return (0);
}

int	check_philo(t_data *data)
{
	int	i;
	int	eat_enough;

	i = 0;
	eat_enough = 1;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_time_lock);
		if (kill_philo(data->philos[i]))
			return (1);
		if (data->num_of_meals != -1)
			if (data->philos[i]->time_ate < data->num_of_meals)
				eat_enough = 0;
		pthread_mutex_unlock(&data->philos[i]->meal_time_lock);
		i++;
	}
	if (data->num_of_meals != -1 && eat_enough == 1)
	{
		set_sim_stop_flag(data, 1);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	data->sim_stop = 0;
	set_sim_stop_flag(data, 0);
	ft_wait(data->start);
	while (1)
	{
		if (check_philo(data) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
