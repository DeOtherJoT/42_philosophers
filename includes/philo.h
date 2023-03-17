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
# define K_EAT 0
# define K_THINK 1
# define K_SLEEP 2
# define K_DEATH 3

// True and False
# define TRUE 0
# define FALSE 1

typedef struct s_data
{
	int	num_philo;
	int	t_2die;
	int	t_2eat;
	int	t_2slp;
	int	num_2eat;
}	t_data;

typedef struct s_philo
{
	pthread_t	th_id;
	size_t		num_id;
	int			l_fork;
	int			r_fork;
	int			num_ate;
	size_t		to_die;
	t_base		*base;
}	t_philo;

typedef struct s_base
{
	t_data			*data;
	int				death_flag;
	int				*fork_stat;
	int				*philo_stat;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	state_mtx;
	pthread_mutex_t	write_mtx;
}	t_base;

/* Input Files */

// parse_args.c
t_data	*parse_args(int argc, char **argv);
t_data	*ft_data_new(char **argv);
void	ft_data_del(t_data *dat);
int		ft_isnum(char *s);
int		check_args(int argc, char **argv);

/* Brains Files */

// begin.c
int		think_tank(t_data *input);
void	*routine(void *arg);

// init_philos.c
t_base	*init_base(t_data *input);
void	init_philos(t_philo **philos, t_data *input);
void	del_base(t_base *base, size_t num_philo);
void	del_philos(t_philo **philos, size_t num_philo);

/* Util Files */

// utils_1.c
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
int		error_msg(char *str, int err_no);
void	*ft_calloc(size_t count, size_t size);
size_t	gettime_ms(void);

#endif