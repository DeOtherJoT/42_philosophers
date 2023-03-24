/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:30:41 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:30:43 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/*
Philos should not be having any forks
*/

void	ft_sleep(t_philo *philo)
{
	if (check_death(philo) == 1)
		return ;
	print_state(philo, C_B, "is sleeping");
	my_usleep(philo, philo->base->data->t_2slp);
}

/*
usleep takes in microsecond, duration is in miliseconds.

In between intervals have to make sure that the death flag is checked.
*/

void	my_usleep(t_philo *philo, size_t duration)
{
	size_t	exit_time;

	exit_time = gettime_ms() + duration;
	while (gettime_ms() < exit_time)
	{
		if (check_death(philo) == 1)
			return ;
		if (gettime_ms() > philo->to_die)
		{
			starve(philo);
			return ;
		}
		usleep(500);
	}
}
