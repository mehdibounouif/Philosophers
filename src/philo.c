/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:40:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/22 09:46:11 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int c, char **v)
{
	t_data	*data;

	data = NULL;
	if (c - 1 < 4 || c - 1 > 5)
		message("Invalid input!\n");
	parss_input(c, v);
	data = init_data(c, v);
	data->philos = init_philos(data);
	start(data);
	stop(data);
	return (EXIT_SUCCESS);
}
