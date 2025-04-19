/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:06:30 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/18 10:26:45 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_stoped(t_data *data)
{
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->sim_stop == 1)
	{
		pthread_mutex_unlock(&data->sim_stop_lock);
		return(1);
	}
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (0);
}

int	main(int c, char **v)
{
	t_data	*data;
	data = NULL;
	if (c - 1 < 4 || c - 1 > 5)
		message(INPUT_MSG);
	is_valid_input(c, v);
	data = ft_init(c, v, data);
  if (!data)
    exit(EXIT_FAILURE);
	start_simulation(data);
	stop_simulation(data);
	exit(EXIT_SUCCESS);
}
