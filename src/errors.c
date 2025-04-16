/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:11:33 by mbounoui          #+#    #+#             */
/*   Updated: 2025/04/16 08:49:59 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_error(t_data *data, char *str)
{
	if (data)
		free_data(data);
	if (str)
		write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
