#include "../../includes/philo.h"

void	print_state(t_philo *philo, int flag)
{
	pthread_mutex_lock(&(philo->base->write_mtx));
	if (flag == K_EAT)
		printf("%s%ld %i %s", C_Y, gettime_ms(), philo->id, "is eating");
	else if (flag == K_THINK)
		printf("%s%ld %i %s", C_G, gettime_ms(), philo->id, "is thinking");
	else if (flag == K_SLEEP)
		printf("%s%ld %i %s", C_B, gettime_ms(), philo->id, "is sleeping");
	else
	{
		if (philo->base->death_flag == 0)
			printf("%s%ld %i %s", C_R, gettime_ms(), philo->id, "is dead");
	}
	printf("%s\n", C_NC);
	pthread_mutex_unlock(&(philo->base->write_mtx));
}

void	starve(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->death_mtx));
	if (philo->base->death_flag == 0)
	{
		philo->base->death_flag = 1;
		print_state(philo, K_DEATH);
	}
	pthread_mutex_unlock(&(philo->base->death_mtx));
}