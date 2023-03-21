#include "../../includes/philo.h"

void	ft_think(t_philo *philo)
{
	// if first time
	if (philo->to_die == 0)
		philo->to_die = gettime_ms() + philo->base->data->t_2die;
	if (philo->base->death_flag == 1)
		return ;
	print_state(philo, K_THINK);
	if (philo->id % 2 != 0)
}