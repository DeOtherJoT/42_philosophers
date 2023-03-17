#include "../../includes/philo.h"

int	think_tank(t_data *input)
{
	t_philo	**philos;
	int		i;

	init_philos(philos, input);
	i = -1;
	while (++i < input->num_philo)
		pthread_create(&(philos[i]->th_id), NULL, &routine, &(philos[i]));
	i = -1;
	while (++i < input->num_philo)
		pthread_join(philos[i]->th_id, NULL);
	del_philos(philos, input->num_philo);
	return (1); // success
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	if (philo->base->data->num_2eat == 0) // run infinitely
	{
		while (1)
		{
			dinner_cycle(philo);
			if (philo->base->death_flag == 1)
				return ;
		}
	}
	else // run only till the desired amount is reached
	{
		i = -1;
		while (++i < philo->base->data->num_2eat)
		{
			dinner_cycle(philo);
			if (philo->base->death_flag == 1)
				return ;
		}
	}
}

void	dinner_cycle(t_philo *philo)
{
	ft_think(philo);
	ft_sleep(philo);
	ft_eat(philo);
}