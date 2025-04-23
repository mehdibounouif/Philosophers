/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:40:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/23 09:17:07 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char **v)
{
	t_data	*data;

	data = NULL;
	if (c != 5 && c != 6)
		message("Invalid input!\n");
	parss_input(c, v);
	data = init_data(c, v);
	data->philos = init_philos(data);
	init_mutexes(data);	
	start(data);
	stop(data);
	return (0);
}
