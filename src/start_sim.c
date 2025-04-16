/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:08:47 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 10:10:58 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_routine(t_philo *philo)
{
	display(philo, "has taken a fork");
	philo_sleep(philo->data, philo->data->time_to_die);
	display(philo, "died");
}

void	*philos_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->data->time_to_die == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (philo->data->num_of_philos == 1)
		return (single_routine(philo), NULL);
	else if (philo->id % 2)
		think_mode(philo, 1);
	while (!has_simulation_stopped(philo->data))
	{
		// eat and sleep are same.
		sleep_mode(philo);
		think_mode(philo, 0);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start = current_time() + (data->num_of_philos * 20);
	if (data->num_of_meals == 0)
		print_error(data, "No meals to eat!\n");
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i]->thread, NULL,
					 &philos_routine, data->philos[i]))
			print_error(data, "Failed to create thread!\n");
		i++;
	}
	if (data->num_of_philos > 1)
		if (pthread_create(&data->monitor, NULL,
					 &monitor_routine, data))
			print_error(data, "Failed to create thread!\n");
}
