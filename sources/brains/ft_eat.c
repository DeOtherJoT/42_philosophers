#include "../../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	// forks grabbed, time to eat
	size_t	time_now;

	if (philo->base->death_flag == 1)
		return ;
	time_now = gettime_ms();
	if (time_now > philo->to_die)
	{
		starve(philo);
		return ;
	}
	print_state(philo, C_Y, "is eating");
	philo->num_ate += 1;
	unlock_forks(philo, philo->l_fork, philo->r_fork);
	philo->to_die += philo->base->data->t_2die;
	my_usleep(philo, philo->base->data->t_2eat);
}

void	starve(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->death_mtx));
	if (philo->base->death_flag == 0)
	{
		philo->base->death_flag = 1;
		unlock_forks(philo, philo->l_fork, philo->r_fork);
		print_death(philo);
	}
	pthread_mutex_unlock(&(philo->base->death_mtx));
}

void	unlock_forks(t_philo *philo, int l_fork, int r_fork)
{
	pthread_mutex_unlock(&(philo->base->fork_mtx[l_fork]));
	pthread_mutex_unlock(&(philo->base->fork_mtx[r_fork]));
	pthread_mutex_lock(&(philo->base->fstate_mtx));
	philo->base->fork_stat[l_fork] = 0;
	philo->base->fork_stat[r_fork] = 0;
	pthread_mutex_lock(&(philo->base->fstate_mtx));
}