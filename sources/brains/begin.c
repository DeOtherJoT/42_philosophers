/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:30:27 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:30:28 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	dinner_table(t_data *input)
{
	t_philo	*philos;
	size_t	i;

	philos = init_philos(input);
	i = -1;
	while (++i < input->num_philo)
		pthread_create(&(philos[i].th_id), NULL, &routine, &(philos[i]));
	i = -1;
	while (++i < input->num_philo)
		pthread_join((philos[i].th_id), NULL);
	del_philos(&philos, input->num_philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	size_t	i;

	philo = (t_philo *)arg;
	if (philo->base->data->num_2eat == 0)
	{
		while (check_death(philo) != 1)
			dinner_cycle(philo);
	}
	else
	{
		i = -1;
		while (++i < philo->base->data->num_2eat)
		{
			dinner_cycle(philo);
			if (check_death(philo) == 1)
				break ;
		}
	}
	return (NULL);
}

void	dinner_cycle(t_philo *philo)
{
	ft_think(philo);
	ft_eat(philo);
	ft_sleep(philo);
}
