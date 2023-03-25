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

/**
 * @brief	Driver function for the philo algorithm.
 * 			1.	Creates an array of t_philo structs, each representing a
 * 				philosopher.
 * 			2.	A thread is then created for each philosopher and they run
 * 				their routines, and joined back to once done.
 * 			3.	Each struct is then freed.
 * 
 * @param input	the t_data struct with the input args parsed.
 */

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

/**
 * @brief	Routine function that is run by each thread. Depending on whether
 * 			the optional argument is provided.
 * 
 * @param arg
 * @return void* 
 */

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

/**
 * @brief	Cycles through helper functions that represent each state
 * 			a philosopher can be in. The cycle is ends if a philo dies or
 * 			the number of times to eat is fulfilled.
 * 
 * @param philo 
 */

void	dinner_cycle(t_philo *philo)
{
	ft_think(philo);
	ft_eat(philo);
	ft_sleep(philo);
}
