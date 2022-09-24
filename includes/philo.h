#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_data
{
	int	num_philo;
	int	time_2die;
	int	time_2eat;
	int	time_2slp;
	int	num_2eat;
}	t_data;

/* Input Files */

// Parse Arguments
t_data	*parse_args(int argc, char **argv);
t_data	*ft_data_new(char **argv);
void	ft_data_del(t_data *dat);

/* General Utils */
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
int		error_msg(char *str);

#endif