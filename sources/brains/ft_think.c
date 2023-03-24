/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:30:48 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:30:49 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	grab_fork(t_philo *philo, t_base *base, int fork)
{
	while (gettime_ms() < philo->to_die)
	{
		if (check_death(philo) == 1)
			return (0);
		pthread_mutex_lock(&(base->fstate_mtx));
		if (base->fork_stat[fork] == 0)
		{
			base->fork_stat[fork] = 1;
			pthread_mutex_lock(&(base->fork_mtx[fork]));
			print_state(philo, C_W, "has taken a fork");
			pthread_mutex_unlock(&(base->fstate_mtx));
			return (1);
		}
		pthread_mutex_unlock(&(base->fstate_mtx));
		usleep(500);
	}
	starve(philo);
	return (0);
}

static void	queue_forks(t_philo *philo, int l_fork, int r_fork)
{
	if (grab_fork(philo, philo->base, l_fork) == 0)
		return ;
	if (grab_fork(philo, philo->base, r_fork) == 0)
	{
		pthread_mutex_unlock(&(philo->base->fork_mtx[l_fork]));
		pthread_mutex_lock(&(philo->base->fstate_mtx));
		philo->base->fork_stat[l_fork] = 0;
		pthread_mutex_unlock(&(philo->base->fstate_mtx));
		return ;
	}
}

void	ft_think(t_philo *philo)
{
	if (philo->to_die == 0)
		philo->to_die = gettime_ms() + philo->base->data->t_2die;
	if (check_death(philo) == 1)
		return ;
	print_state(philo, C_G, "is thinking");
	if (philo->id % 2 != 0)
		usleep((philo->base->data->t_2eat) * 0.5);
	queue_forks(philo, philo->l_fork, philo->r_fork);
}
