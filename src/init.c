#include "../includes/philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	data->fork_locks = malloc(sizeof(pthread_metux_t) * data->num_philos);
	if (!data->fork_locks)
		return (NULL); // free() here
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->fork_locks[i], NULL))
			return (NULL); // free() here
		i++;
	}
	if (pthread_mutex_init(&data->sim_stop_lock, NULL))
		return (NULL); // free() here
	if (pthread_mutex_init(&data->write_lock, NULL))
		return (NULL); // free() here

}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->nb_philos;
		philo->fork[1] = philo->id;
	}
	else
	{
		philo->fork[0] = philo->id;
		philo->fork[1] = (philo->id + 1) % philo->data->nb_philos;
	}
}

t_philo	**init_philos(t_data *data)
{
	t_philo	**philos;
	int	i;

	if (!(philos = malloc(sizeof(t_philo) * data->num_philos)))
		return NULL; // free() here
	i = 0;
	while (i < table->num_philos)
	{
		if (data->philo[i] = malloc(sizeof(t_philo)))
			return (NULL); // free() here
		if (pthread_mutex_init(&philo[i]->meal_time_lock))
			return (NULL); // free() here
		philo[i]->data = data;
		philo[i]->id = i;
		philo[i]->times_ate = 0;
		take_forks(philoa[i]);
		i++;
	}
	return (philos);
}

t_data	*init(int c, char **v)
{
	if (data = malloc(sizeof(t_data)))
		return (NULL);
	data->num_philos = atoi(v[1]);
	data->time_to_die = atoi(v[2]);
	data->time_to_eat = atoi(v[3]);
	data->time_to_sleep = atoi(v[4]);
	data->sim_stop = 0;
	if (c == 6)
		data->must_eat_count = atoi(v[5]);
	else
		data->must_eat_count = -1;
	data->philos = init_philos(data);
	init_mutexes(data);
	return (data);
}
