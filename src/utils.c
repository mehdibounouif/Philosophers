/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:45:54 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/21 08:57:53 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
		free(table->philos[i++]);
	free(table->philos);
	i = 0;
	while (i < table->nb_philos)
		pthread_mutex_destroy(&table->fork_locks[i++]);
	free(table->fork_locks);
	pthread_mutex_destroy(&table->sim_stop_lock);
	pthread_mutex_destroy(&table->write_lock);
}

void	destroy_mutexes(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->fork_locks[i]);
		pthread_mutex_destroy(&table->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->sim_stop_lock);
}

void	message(char	*msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	ft_error(t_table *table, char *msg)
{
	if (table)
		ft_free(table);
	if (msg)
		message(msg);
	exit(EXIT_FAILURE);
}
