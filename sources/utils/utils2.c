#include "../../includes/philo.h"

void	print_state(t_philo *philo, int flag)
{
	pthread_mutex_lock(&(philo->base->state_mtx));
	if (flag == K_EAT)
		printf("%s%ld %i %s", C_Y, gettime_ms(), philo->id, "is eating");
	else if (flag == K_THINK)
		printf("%s%ld %i %s", C_G, gettime_ms(), philo->id, "is thinking");
	else if (flag == K_SLEEP)
		printf("%s%ld %i %s", C_B, gettime_ms(), philo->id, "is sleeping");
	else
		printf("%s%ld %i %s", C_R, gettime_ms(), philo->id, "is dead");
	printf("%s\n", C_N);
	pthread_mutex_unlock(&(philo->base->state_mtx));
}