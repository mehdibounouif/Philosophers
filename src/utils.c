/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:45:54 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/28 09:04:48 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->fork_locks[i++]);
	}
	free(data->fork_locks);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->stop_lock);
}

void	message(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
		pthread_mutex_destroy(&data->philos[i++].meal_lock);
	if (data->philos)
		free(data->philos);
	destroy_mutexes(data);
}

void	ft_error(t_data *data, char *msg)
{
	if (data)
		ft_free(data);
	if (msg)
		return (message(msg));
	return ;
}
