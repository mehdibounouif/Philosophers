/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:12:25 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 11:01:54 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start(t_data *data)
{
	unsigned int	i;

	data->start = current_time() + (data->num_of_philos * 2 * 10);
	i = 0;
	if (data->num_of_meals == 0)
		ft_error(data, "Makayn mayt9asa!\n");
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i]->thread, NULL,
				&life_of_philo, data->philos[i]) != 0)
			ft_error(data, "pthread_create failed!\n");
		i++;
	}
	if (data->num_of_philos > 1)
	{
		if (pthread_create(&data->monitor_routine, NULL,
				&monitor_routine, data) != 0)
			ft_error(data, "pthread_create failed!\n");
	}
}
