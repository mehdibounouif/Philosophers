/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:14:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/28 09:03:51 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	stop(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	if (data->num_of_philos > 1)
		pthread_join(data->monitor_routine, NULL);
	ft_free(data);
}
