/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:40:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/28 09:02:19 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char **v)
{
	t_data	data;

	if (c != 5 && c != 6)
		return (message("Invalid input!\n"), 1);
	if (!parss_input(c, v))
		return (2);
	init_data(c, v, &data);
	data.philos = init_philos(&data);
	if (!data.philos)
		return (3);
	if (!init_mutexes(&data))
		return (4);
	if (!start(&data))
		return (5);
	stop(&data);
	return (0);
}
