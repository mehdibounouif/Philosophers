/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:45:54 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 14:19:14 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_strcmp(char *s1, char *s2)
{
  while (*s1)
  {
    if (*s1 != *s2)
      return (*s1 - *s2);
    s1++;
    s2++;
  }
  return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
		free(data->philos[i++]);
	free(data->philos);
	i = 0;
	while (i < data->num_of_philos)
		pthread_mutex_destroy(&data->fork_locks[i++]);
	free(data->fork_locks);
	pthread_mutex_destroy(&data->sim_stop_lock);
	pthread_mutex_destroy(&data->write_lock);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->fork_locks[i]);
		pthread_mutex_destroy(&data->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->sim_stop_lock);
}

void	message(char	*msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	ft_error(t_data *data, char *msg)
{
	if (data)
		ft_free(data);
	if (msg)
		message(msg);
	exit(EXIT_FAILURE);
}
