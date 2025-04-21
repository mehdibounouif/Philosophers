/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:46:40 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 07:46:41 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	set_sim_stop_flag(t_data *data, bool state)
{
	pthread_mutex_lock(&data->sim_stop_lock);
		data->sim_stop = state;
	pthread_mutex_unlock(&data->sim_stop_lock);
}

bool	is_stoped(t_data *data)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->sim_stop == true)
		r = true;
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (r);
}

static bool	kill_philo(t_philo *philo)
{
	time_t	time;

	time = current_time();
	if ((time - philo->last_meal) >= philo->data->time_to_die)
	{
		set_sim_stop_flag(philo->data, true);
		write_status(philo, true, "died");
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (true);
	}
	return (false);
}

static bool	end_condition_reached(t_data *data)
{
	unsigned int	i;
	bool			all_ate_enough;

	all_ate_enough = true;
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->philos[i]->meal_time_lock);
		if (kill_philo(data->philos[i]))
			return (true);
		if (data->num_of_meals != -1)
			if (data->philos[i]->times_ate
				< (unsigned int)data->num_of_meals)
				all_ate_enough = false;
		pthread_mutex_unlock(&data->philos[i]->meal_time_lock);
		i++;
	}
	if (data->num_of_meals != -1 && all_ate_enough == true)
	{
		set_sim_stop_flag(data, true);
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *args)
{
	t_data			*data;

	data = (t_data *)args;
	if (data->num_of_meals == 0)
		return (NULL);
	set_sim_stop_flag(data, false);
	wait_others(data->start);
	while (true)
	{
		if (end_condition_reached(data) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
