#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Colours of each state
# define C_EAT "\033[0;33m"    /* YELLOW */
# define C_THINK "\033[0;32m"  /* GREEN  */
# define C_SLEEP "\033[0;34m"  /* BLUE   */
# define C_DEATH "\033[0;31m"  /* RED    */
# define C_RESET "\033[0m"     /* RESET  */

// Integer Keys of each state
# define K_EAT 384
# define K_THINK 551
# define K_SLEEP 470
# define K_DEATH 1724

// True and False
# define TRUE 0
# define FALSE 1

typedef struct s_data
{
	int	num_philo;
	int	time_2die;
	int	time_2eat;
	int	time_2slp;
	int	num_2eat;
}	t_data;

typedef struct s_philo
{
	size_t	id;
	t_data	*data;
}	t_philo;

typedef struct s_base
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	state_shift;
	pthread_mutex_t	write_mutex;
}	t_base;

/* Brain Files */

// begin.c
int	think_tank(t_data *input, int argc);

/* Input Files */

// parse_args.c
t_data	*parse_args(int argc, char **argv);
t_data	*ft_data_new(char **argv);
void	ft_data_del(t_data *dat);
int		ft_isnum(char *s);
int		check_args(int argc, char **argv);

/* Util Files */

// utils_1.c
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
int		error_msg(char *str, int err_no);
size_t	gettime_ms(void);

#endif