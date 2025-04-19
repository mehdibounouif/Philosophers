/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:08:47 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/18 10:14:07 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	single_routine(t_philo *philo)
{
	display(philo, "has taken a fork");
	ft_sleep(philo->data, philo->data->time_to_die);
	display(philo, "died");
}

void	*philos_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->data->num_of_meals == 0)
		print_error(philo->data, "No meals to eat!\n");
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->meal_time_lock);
	ft_wait(philo->data->start);
	if (philo->data->time_to_die == 0)
		return (NULL);
	if (philo->data->num_of_philos == 1)
		return (single_routine(philo), NULL);
	else if (philo->id % 2)
		think_mode(philo, 1);
	while (is_stoped(philo->data) == 0)
	{
		// eat and sleep are same.
		eat_mode(philo);
		think_mode(philo, 0);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start = current_time() + (data->num_of_philos * 2 * 10);
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
