#include "../../includes/philo.h"

void	ft_think(t_philo *philo)
{
	// if first time
	if (philo->to_die == 0)
		philo->to_die = gettime_ms() + philo->base->data->t_2die;
	if (philo->base->death_flag == 1)
		return ;
	print_state(philo, C_G, "is thinking");
	if (philo->id % 2 != 0)
		usleep((philo->base->data->t_2eat) * 0.9);
	queue_forks(philo, philo->l_fork, philo->r_fork);
}

void	queue_forks(t_philo *philo, int l_fork, int r_fork)
{
	if (grab_fork(philo, philo->base, l_fork) == 0)
		return ;
	if (grab_fork(philo, philo->base, r_fork) == 0)
	{
		pthread_mutex_unlock(&(philo->base->fork_mtx[l_fork]));
		return ;
	}
}

int	grab_fork(t_philo *philo, t_base *base, int fork)
{
	size_t	time_now;

	while (1)
	{
		time_now = gettime_ms();
		if (base->death_flag == 1)
			return (0);
		if (time_now > philo->to_die)
		{
			pthread_mutex_lock(&(base->death_mtx));
			base->death_flag = 1;
			print_death(philo);
			pthread_mutex_unlock(&(base->death_mtx));
			return (0);
		}
		if (base->fork_stat[fork] == 0)
		{
			pthread_mutex_lock(&(base->fstate_mtx));
			base->fork_stat[fork] = 1;
			pthread_mutex_lock(&(base->fork_mtx[fork]));
			pthread_mutex_unlock(&(base->fstate_mtx));
			return (1);
		}
		usleep(500);
	}
}
