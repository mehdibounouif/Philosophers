/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:08:47 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 09:16:17 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	*philos_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	return (NULL);
}


void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start = current_time() + (data->num_of_philos * 20);	
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i]->thread, NULL, &philos_routine, data->philos[i]))
			print_error(data, "Failed to create thread!\n");
		i++;
	}
	if (data->num_of_philos > 1)
		if (pthread_create(&data->monitor, NULL, &monitor_routine, data))
			print_error(data, "Failed to create thread!\n");
}

