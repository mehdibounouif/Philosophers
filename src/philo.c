/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:40:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/24 17:54:05 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char **v)
{
	t_data	*data;

	data = NULL;
	if (c != 5 && c != 6)
		return (message("Invalid input!\n"), 1);
	if (!parss_input(c, v))
		return (1);
	data = init_data(c, v);
	if (!data)
		return (1);
	data->philos = init_philos(data);
	if (!data->philos)
		return (1);
	if (!init_mutexes(data))
		return (1);
	start(data);
	stop(data);
	return (0);
}
