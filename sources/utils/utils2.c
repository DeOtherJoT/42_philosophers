#include "../../includes/philo.h"

void	print_state(t_philo *philo, char *colour, char *str)
{
	pthread_mutex_lock(&(philo->base->write_mtx));
	if (philo->base->death_flag == 0)
		printf("%s%zu %zu %s%s\n", colour, gettime_ms(), philo->id, str, C_NC);
	pthread_mutex_unlock(&(philo->base->write_mtx));
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->write_mtx));
	printf("%s%zu %zu %s%s\n", C_R, gettime_ms(), philo->id, "died", C_NC);
	pthread_mutex_unlock(&(philo->base->write_mtx));
}