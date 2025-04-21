/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:47:31 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 08:56:06 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!forks)
		ft_error(data, "Malloc failed!\n");
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			ft_error(data, "pthread_mutex_init failed!\n");
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->data->num_of_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->num_of_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**init_philosophers(t_data *data)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!philos)
		ft_error(data, "Malloc failed!\n");
	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			ft_error(data, "Malloc failed!\n");
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			ft_error(data, "pthread_mutex_init failed!\n");

		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static bool	init_global_mutexes(t_data *data)
{
	data->fork_locks = init_forks(data);
	if (!data->fork_locks)
		return (false);
	if (pthread_mutex_init(&data->sim_stop_lock, 0) != 0)
		ft_error(data, "pthread_mutex_init failed!\n");
	if (pthread_mutex_init(&data->write_lock, 0) != 0)
		ft_error(data, "pthread_mutex_init failed!\n");
	return (true);
}

t_data	*init_data(int ac, char **av, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		ft_error(data, "Malloc failed!\n");

	data->num_of_philos = ft_atoi(av[i++]);
	data->time_to_die = ft_atoi(av[i++]);
	data->time_to_eat = ft_atoi(av[i++]);
	data->time_to_sleep = ft_atoi(av[i++]);
	data->num_of_meals = -1;
	if (ac - 1 == 5)
		data->num_of_meals = ft_atoi(av[i]);
	data->philos = init_philosophers(data);
	if (!data->philos)
		return (NULL);
	if (!init_global_mutexes(data))
		return (NULL);
	data->sim_stop = false;
	return (data);
}
