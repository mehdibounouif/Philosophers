#include "../includes/philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	data->forks_locks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks_locks)
		return ; // free() here
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks_locks[i], NULL))
			return ; // free() here
		i++;
	}
	if (pthread_mutex_init(&data->sim_stop_lock, NULL))
		return ; // free() here
	if (pthread_mutex_init(&data->write_lock, NULL))
		return ; // free() here

}

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
	int	i;

	if (!(philos = malloc(sizeof(t_philo) * data->num_of_philos)))
		return NULL; // free() here
	i = 0;
	while (i < data->num_of_philos)
	{
		if (data->philos[i] = malloc(sizeof(t_philo)))
			return (NULL); // free() here
		if (pthread_mutex_init(&philos[i]->meal_time_lock, NULL))
			return (NULL); // free() here
		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->time_ate = 0;
		take_forks(philos[i]);
		i++;
	}
	return (philos);
}

t_data	*init(int c, char **v, t_data *data)
{
	data->num_of_philos = atoi(v[1]);
	data->time_to_die = atoi(v[2]);
	data->time_to_eat = atoi(v[3]);
	data->time_to_sleep = atoi(v[4]);
	data->sim_stop = 0;
	if (c == 6)
		data->num_of_meals = atoi(v[5]);
	else
		data->num_of_meals = -1;
	data->philos = init_philos(data);
	init_mutexes(data);
	return (data);
}
