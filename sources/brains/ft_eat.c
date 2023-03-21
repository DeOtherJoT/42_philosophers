#include "../../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	// forks grabbed, time to eat
	size_t	time_now;

	if (philo->base->death_flag == 1)
		return ;
	time_now = gettime_ms();
	if (time_now > philo->to_die)
		starve(philo);
	print_state(philo, K_EAT);
	unlock_forks(philo, philo->l_fork, philo->r_fork);
	philo->to_die += philo->base->data->t_2die;
	ft_sleep(philo->base->data->t_2eat);
}

void	unlock_forks(t_philo *philo, int l_fork, int r_fork)
{
	pthread_mutex_unlock(&(philo->base->fork_mtx[l_fork]));
	pthread_mutex_unlock(&(philo->base->fork_mtx[r_fork]));
}