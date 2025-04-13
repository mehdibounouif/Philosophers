#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

typedef struct s_data
{
	pthread_t	monitor; // thread monitoring philosopher deaths.
	pthread_mutex_t	sim_stop_lock; // proticting sim_stop from race condition.
	pthread_mutex_t	*forks_locks; // array of mutexs each representing a fork.
	pthread_mutex_t	write_lock; // mutex controling console output
	time_t	start; // start time when the simulation started.
	time_t	time_to_die; // time of philosopher can stay without eating.
	time_t	time_to_eat; // time of philosopher while eating.
	time_t	time_to_sleep; // time of philosopher while sleeping.
	int	num_of_meals; // number of meal any philosopher must eat (minimum).
	int	sim_stop; // check if philo is death.
	int	num_of_philos; // number of philosophers.
	t_philo	**philos; // list of philosopher with his components.
}	t_data;

typedef	struct	s_philo
{
	pthread_t	thread; // philosopher
	pthread_mutext_t	meal_time_lock; // protecting last meal 
	int	id; // philo id 
	int	time_ate; // number of times the philosopher has eaten.
	int	fork[2]; // indices of two forks
	time_t	last_meal; // time of the philosopher's last meal.
	t_data	*data; //pointer to data struct.
}	t_philo;

#define INPUT_MSG "Valid input:\n\
	    number of philosophers\n\
	    time_to_die\n\
	    time_to_eat\n\
	    time_to_sleep\n\
	    [number_of_times_each_philosopher_must_eat] (optional).\
	    \n\
	    \nexample:   ./philo 5 200 200 100 2\n"
# define NUMBER_MSG "Wadakha number m9ad kon thcham\n"
# define RANGE_MSG "between 0 and INT_MAX 3AFAK\n"

void	message(char *msg);
int     ft_atoi(char *s);
void	is_valid_input(int c, char **v);
#endif 
