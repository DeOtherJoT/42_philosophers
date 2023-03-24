/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:59 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:32:01 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static size_t	format_ms(t_philo *philo)
{
	return (gettime_ms() - philo->base->start_time);
}

void	print_state(t_philo *philo, char *colour, char *str)
{
	pthread_mutex_lock(&(philo->base->write_mtx));
	if (check_death(philo) == 0)
	{
		printf("%s", colour);
		printf("%010zu %zu %s", format_ms(philo), philo->id, str);
		printf("%s\n", C_NC);
	}
	pthread_mutex_unlock(&(philo->base->write_mtx));
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->write_mtx));
	printf("%s", C_R);
	printf("%010zu %zu %s", format_ms(philo), philo->id, "died");
	printf("%s\n", C_NC);
	pthread_mutex_unlock(&(philo->base->write_mtx));
}

int	check_death(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&(philo->base->death_mtx));
	ret = philo->base->death_flag;
	pthread_mutex_unlock(&(philo->base->death_mtx));
	return (ret);
}
