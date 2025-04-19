/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:09:42 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 09:16:37 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	printf("%d\n", data->num_of_philos);
	return (NULL);
}
