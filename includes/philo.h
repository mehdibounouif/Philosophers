/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:44:20 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 08:51:20 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>


# define STR_PROG_NAME	"philo:"
# define STR_USAGE	"%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define STR_ERR_INPUT_DIGIT	"%s invalid input: %s: \
not a valid unsigned integer between 0 and 2147483647.\n"
# define STR_ERR_INPUT_POFLOW	"%s invalid input: \
there must be between 1 and %s philosophers.\n"
# define STR_ERR_THREAD	"%s error: Could not create thread.\n"
# define STR_ERR_MALLOC	"%s error: Could not allocate memory.\n"
# define STR_ERR_MUTEX	"%s error: Could not create mutex.\n"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	time_t			start;
	unsigned int	num_of_philos;
	pthread_t		monitor_routine;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_of_meals;
	bool			sim_stop;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
}	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_data				*data;
}	t_philo;


void	parss_input(int c, char **v);
int	ft_atoi(char *s);
int		start(t_data *data);
void	stop(t_data	*data);
t_data			*init_data(int ac, char **av, int i);
void			*life_of_philo(void *data);
time_t			current_time(void);
void			philo_sleep(t_data *data, time_t sleep_time);
void			wait_others(time_t start);
void			*monitor_routine(void *args);
void			write_status(t_philo *philo, bool reaper, char *status);
bool			is_stoped(t_data *data);
void			destroy_mutexes(t_data *data);
void	eat_sleep_routine(t_philo *philo);
void	think_routine(t_philo *philo, bool silent);
void	*single(t_philo *philo);
void	ft_error(t_data *data, char *msg);
void	message(char	*msg);
void	ft_free(t_data *data);
int   ft_strcmp(char *s1, char *s2);
#endif
