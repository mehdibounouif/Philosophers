/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:47:31 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/24 14:31:43 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->num_of_philos;
		philo->fork[1] = philo->id;
	}
	else
	{
		philo->fork[0] = philo->id;
		philo->fork[1] = (philo->id + 1) % philo->data->num_of_philos;
	}
}

t_philo	**init_philos(t_data *data)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo *) * data->num_of_philos);
	if (!philos)
		return (ft_error(data, "Malloc failed!\n"), NULL);
	while (i < data->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (ft_error(data, "Malloc failed!\n"), NULL);
		if (pthread_mutex_init(&philos[i]->meal_lock, 0))
			return (ft_error(data, "pthread_mutex_init failed!\n"), NULL);
		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->count_meals = 0;
		take_forks(philos[i]);
		i++;
	}
	return (philos);
}

int	init_mutexes(t_data *data)
{
	int	i;

	data->fork_locks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->fork_locks)
		return (ft_error(data, "pthread_mutex_init failed!\n"), 0);
	i = 0;
	while (i < data->num_of_philos)
		if (pthread_mutex_init(&data->fork_locks[i++], NULL))
			return (ft_error(data, "pthread_mutex_init failed!\n"), 0);
	if (pthread_mutex_init(&data->stop_lock, 0))
		return (ft_error(data, "pthread_mutex_init failed!\n"), 0);
	if (pthread_mutex_init(&data->write_lock, 0))
		return (ft_error(data, "pthread_mutex_init failed!\n"), 0);
	return (1);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (ft_error(data, "Malloc failed!\n"), NULL);
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->stop_flag = 0;
	if (ac == 6)
		data->num_of_meals = ft_atoi(av[5]);
	else
		data->num_of_meals = -1;
	return (data);
}
