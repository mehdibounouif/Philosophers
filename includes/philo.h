/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:49:21 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/18 10:27:08 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef	struct	s_philo t_philo;

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
	int	num_of_meals; // number of meal any philosopher must eat (minimum). int	sim_stop; // check if philo is death.
	int	num_of_philos; // number of philosophers. t_philo	**philos; // list of philosopher with his components.
	int	sim_stop;
	t_philo ** philos;
	//
}	t_data;

typedef	struct	s_philo
{
	pthread_t	thread; // philosopher
	pthread_mutex_t	meal_time_lock; // protecting last meal 
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
t_data  *ft_init(int c, char **v, t_data *data);
int	ft_strlen(char *s);
void	free_data(t_data *data);
void	print_error(t_data *data, char *str);
int   is_stoped(t_data *data);
time_t	current_time(void);
void	*monitor_routine(void *args);
void	*philos_routine(void *args);
void	single_routine(t_philo *philo);
void	start_simulation(t_data *data);
void	stop_simulation(t_data *data);
void	ft_sleep(t_data *data, time_t time);
void	eat_mode(t_philo *philo);
void	think_mode(t_philo *philo, int	flag);
void	display(t_philo *philo, char *status);
void	ft_wait(time_t start_time);
#endif 
