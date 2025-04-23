/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:47:31 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/23 08:47:49 by mbounoui         ###   ########.fr       */
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
	else {
		philo->fork[0] = philo->id;
		philo->fork[1] = (philo->id + 1) % philo->data->num_of_philos;
	
	}
}

t_philo	**init_philos(t_data *data)
{
	int	i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo*) * data->num_of_philos);
	while (i < data->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			ft_error(data, "Malloc failed!\n");
		if (pthread_mutex_init(&philos[i]->meal_lock, 0))
			ft_error(data, "pthread_mutex_init failed!\n");
		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		take_forks(philos[i]);
		i++;
	}
	return (philos);
}

void	init_mutexes(t_data *data)
{
	int	i;

	data->fork_locks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->fork_locks)
		ft_error(data, "pthread_mutex_init failed!\n");
	i = 0;
	while (i < data->num_of_philos)	
		if (pthread_mutex_init(&data->fork_locks[i++], NULL))
			ft_error(data, "pthread_mutex_init failed!\n");	
	if (pthread_mutex_init(&data->stop_lock, 0))
		ft_error(data, "pthread_mutex_init failed!\n");
	if (pthread_mutex_init(&data->write_lock, 0))
		ft_error(data, "pthread_mutex_init failed!\n");
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		ft_error(data, "Malloc failed!\n");
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->stop_flag = 0;
	if (ac - 1 == 5)
		data->num_of_meals = ft_atoi(av[5]);
	else 
		data->num_of_meals = -1;
	return (data); 
}
