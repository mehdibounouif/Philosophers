/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:44:20 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/30 08:46:03 by mbounoui         ###   ########.fr       */
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
typedef pthread_mutex_t	t_m;
typedef struct s_data
{
	pthread_t		monitor_routine;
	t_m				stop_lock;
	t_m				write_lock;
	t_m				*fork_locks;
	int				num_of_philos;
	time_t			start;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_of_meals;
	int				stop_flag;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	t_m					meal_lock;
	pthread_t			thread;
	int					id;
	int					count_meals;
	int					fork[2];
	time_t				last_meal;
	t_data				*data;
}	t_philo;

int			parss_input(int c, char **v);
int			ft_atoi(char *s);
int			ft_strcmp(char *s1, char *s2);
int			is_space(char c);
int			ft_strlen(char *str);
void		message(char	*msg);
void		ft_error(t_data *data, char *msg);
void		ft_free(t_data *data);
void		destroy_mutexes(t_data *data);
int			start(t_data *data);
void		stop(t_data	*data);
void		*life_of_philo(void *data);
void		*monitor_routine(void *args);
t_data		*init_data(int ac, char **av, t_data *data);
t_philo		*init_philos(t_data *data);
int			init_mutexes(t_data *data);
time_t		current_time(void);
void		philo_sleep(t_data *data, time_t sleep_time);
void		wait_others(time_t start);
void		write_status(t_philo *philo, char *status);
int			is_stoped(t_data *data);
#endif
