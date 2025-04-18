/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:16:47 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/18 10:18:06 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	is_valid_input(int c, char **v)
{
	int	i;
	long	nb;

	i = 1;
	while (i < c)
	{
		nb = ft_atoi(v[i]);
		if ((nb <= 0 || nb > INT_MAX) && i != 5)
			message(RANGE_MSG);
		i++;
	}
}

void	message(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	print_error(t_data *data, char *str)
{
	if (data)
		free_data(data);
	if (str)
		message(str);
	exit(EXIT_FAILURE);
}

void	display(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	printf("%ld %d %s\n", current_time() - philo->data->start,
		philo->id + 1, status);
	pthread_mutex_unlock(&philo->data->write_lock);
}
