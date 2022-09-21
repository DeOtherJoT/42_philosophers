#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_data
{
	int		num_philo;
	size_t	time_2die;
	size_t	time_2eat;
	size_t	time_2slp;
	ssize_t	num_2eat;
}	t_data;


#endif