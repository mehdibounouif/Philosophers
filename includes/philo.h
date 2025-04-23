/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:44:20 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/23 09:19:43 by mbounoui         ###   ########.fr       */
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

typedef struct s_philo	t_philo;
typedef	pthread_mutex_t m_t;
typedef struct s_data
{
	pthread_t		monitor_routine; // routine of monitor 
	m_t	stop_lock; // protecte stop flag 
	m_t	write_lock; // protect output
	m_t	*fork_locks; // protect forks
	int	num_of_philos; // number of philosophers
	time_t			start; // start time of philosophers routine
	time_t			time_to_die; // time of die
	time_t			time_to_eat; // time of eat
	time_t			time_to_sleep; // time of sleep
	int				num_of_meals; // numbers of meals (this param is optional)
	int				stop_flag; // through this flag i know the state of the philosophers
	t_philo			**philos; // philosophers
}	t_data;

typedef struct s_philo
{
	pthread_t			thread; // thread
	int		id; // philosophers id 
	int		count_meals; // how many is eat
	int		fork[2]; // forks
 	m_t		meal_lock; // protecte meal
	time_t				last_meal; // time of last meal
	t_data				*data; // pointer to data struct
}	t_philo;


void	parss_input(int c, char **v);
int	ft_atoi(char *s);
int   ft_strcmp(char *s1, char *s2);
void	message(char	*msg);
void	ft_error(t_data *data, char *msg);
void	ft_free(t_data *data);
void			destroy_mutexes(t_data *data);
void	start(t_data *data);
void	stop(t_data	*data);
void			*life_of_philo(void *data);
void			*monitor_routine(void *args);
t_data	*init_data(int ac, char **av);
t_philo		**init_philos(t_data *data);
void	init_mutexes(t_data *data);
time_t			current_time(void);
void			philo_sleep(t_data *data, time_t sleep_time);
void			wait_others(time_t start);
void	write_status(t_philo *philo, char *status);
int			is_stoped(t_data *data);
#endif
