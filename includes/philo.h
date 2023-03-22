#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Colours of each state
# define C_Y "\033[0;33m"	/* EAT   */
# define C_G "\033[0;32m"	/* THINK */
# define C_B "\033[0;34m"	/* SLEEP */
# define C_R "\033[0;31m"   /* DEATH */
# define C_W "\033[0;37m"	/* FORK  */
# define C_NC "\033[0m"		/* RESET */

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
	size_t	num_philo;
	size_t	t_2die;
	size_t	t_2eat;
	size_t	t_2slp;
	size_t	num_2eat;
}	t_data;

typedef struct s_base
{
	t_data			*data;
	int				death_flag;
	int				*fork_stat;
	pthread_mutex_t	*fork_mtx;
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	write_mtx;
	pthread_mutex_t	fstate_mtx;
}	t_base;

typedef struct s_philo
{
	pthread_t	th_id;
	size_t		id;
	int			l_fork;
	int			r_fork;
	int			num_ate;
	size_t		to_die;
	t_base		*base;
}	t_philo;


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
void	dinner_cycle(t_philo *philo);

// ft_eat.c
void	ft_eat(t_philo *philo);
void	unlock_forks(t_philo *philo, int l_fork, int r_fork);
void	starve(t_philo *philo);

// ft_sleep.c
void	ft_sleep(t_philo *philo);
void	my_usleep(t_philo *philo, size_t duration);

// ft_think.c
void	ft_think(t_philo *philo);
void	queue_forks(t_philo *philo, int l_fork, int r_fork);
int		grab_fork(t_philo *philo, t_base *base, int fork);

// init_philos.c
t_base	*init_base(t_data *input);
void	init_philos(t_philo ***philos, t_data *input);
void	del_base(t_base *base, size_t num_philo);
void	del_philos(t_philo **philos, size_t num_philo);

/* Util Files */

// utils_1.c
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
int		error_msg(char *str, int err_no);
void	*ft_calloc(size_t count, size_t size);
size_t	gettime_ms(void);

// utils2.c
void	print_state(t_philo *philo, char *colour, char *str);
void	print_death(t_philo *philo);

#endif