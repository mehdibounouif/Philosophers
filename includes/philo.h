#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define INPUT_MSG "Valid input:\n\
	    number of philosophers\n\
	    time_to_die\n\
	    time_to_eat\n\
	    time_to_sleep\n\
	    [number_of_times_each_philosopher_must_eat] (optional).\
	    \n\
	    \nexample:   ./philo 5 200 200 100 2\n"
# define NUMBER_MSG "Wadakha number m9ad kon thcham\n"
# define RANGE_MSG "between 0 and INT_MAX 3AFAK\n"

void	message(char *msg);
int     ft_atoi(char *s);
int     is_valid_input(int c, char **v);
#endif 
