/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:30:34 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:30:36 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	unlock_forks(t_philo *philo, int l_fork, int r_fork)
{
	pthread_mutex_unlock(&(philo->base->fork_mtx[l_fork]));
	pthread_mutex_unlock(&(philo->base->fork_mtx[r_fork]));
	pthread_mutex_lock(&(philo->base->fstate_mtx));
	philo->base->fork_stat[l_fork] = 0;
	philo->base->fork_stat[r_fork] = 0;
	pthread_mutex_unlock(&(philo->base->fstate_mtx));
}

void	ft_eat(t_philo *philo)
{
	if (check_death(philo) == 1)
		return ;
	if (gettime_ms() > philo->to_die)
	{
		starve(philo);
		return ;
	}
	print_state(philo, C_Y, "is eating");
	philo->to_die += philo->base->data->t_2die;
	my_usleep(philo, philo->base->data->t_2eat);
	philo->num_ate += 1;
	unlock_forks(philo, philo->l_fork, philo->r_fork);
}

void	starve(t_philo *philo)
{
	pthread_mutex_lock(&(philo->base->death_mtx));
	if (philo->base->death_flag == 0)
	{
		philo->base->death_flag = 1;
		unlock_forks(philo, philo->l_fork, philo->r_fork);
		print_death(philo);
	}
	pthread_mutex_unlock(&(philo->base->death_mtx));
}
