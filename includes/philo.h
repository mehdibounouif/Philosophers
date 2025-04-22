/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:44:20 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 11:16:19 by mbounoui         ###   ########.fr       */
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

typedef struct s_philo	t_philo;
typedef	pthread_mutex_t m_t;
typedef struct s_data
{
	pthread_t		monitor_routine;
	m_t	sim_stop_lock;
	m_t	write_lock;
	m_t	*fork_locks;
	unsigned int	num_of_philos;
	time_t			start;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_of_meals;
	int				stop_flag;
	t_philo			**philos;
}	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	m_t		meal_time_lock;
	time_t				last_meal;
	t_data				*data;
}	t_philo;


void	parss_input(int c, char **v);
int	ft_atoi(char *s);
void	start(t_data *data);
void	stop(t_data	*data);
t_data	*init_data(int ac, char **av);
t_philo		**init_philos(t_data *data);
void			*life_of_philo(void *data);
time_t			current_time(void);
void			philo_sleep(t_data *data, time_t sleep_time);
void			wait_others(time_t start);
void			*monitor_routine(void *args);
void	write_status(t_philo *philo, char *status);
int	philo_state(t_data *data);
int			is_stoped(t_data *data);
int			is_kill(t_philo *philo);
void			destroy_mutexes(t_data *data);
//void	set_sim_stop_flag(t_data *data, int state);
void	eat_sleep_routine(t_philo *philo);
void	think_routine(t_philo *philo);
void	*single(t_philo *philo);
void	ft_error(t_data *data, char *msg);
void	message(char	*msg);
void	ft_free(t_data *data);
int   ft_strcmp(char *s1, char *s2);
#endif
