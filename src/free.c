/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:16:12 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 08:46:15 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
		free(data->philos[i++]);
	free(data->philos);
	i = 0;
	while (i < data->num_of_philos)
		pthread_mutex_destroy(&data->forks_locks[i++]);
	free(data->forks_locks);
	pthread_mutex_destroy(&data->sim_stop_lock);
	pthread_mutex_destroy(&data->write_lock);	
}
