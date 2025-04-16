/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:06:30 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 09:14:34 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	has_simulation_stopped(t_data *data)
{
	int	r;

	r = 0;
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->sim_stop)
		r = 1;

	pthread_mutex_unlock(&data->sim_stop_lock);
	return (r);
}

int	main(int c, char **v)
{
	t_data	*data;
	data = malloc(sizeof(t_data));
	if (!data)
                return (1);
	if (c - 1 < 4 || c - 1 > 5)
		message(INPUT_MSG);
	is_valid_input(c, v);
	init(c, v, data);
	start_simulation(data);
	//stop_simulation(data);
	exit(EXIT_SUCCESS);
}
