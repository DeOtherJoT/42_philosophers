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

/**
 * @brief	Constantly check if the fork is available till either the fork
 * 			is taken or the philo dies.
 * 
 * @param philo	the philosopher trying to take the fork
 * @param base	the struct holding the mutexes and shared data
 * @param fork	the fork to be taken
 * 
 */

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

/**
 * @brief	Tries to take the left fork, then the right fork. On failure,
 * 			release the taken fork and exit.
 * 
 * @param philo		The philo takinf the forks
 * @param l_fork	The left fork
 * @param r_fork	The right fork
 */

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

/**
 * @brief	First function in the cycle.
 * 			1.	First, if it's the first cycle, the time to die is initialised.
 * 			2.	Next, always checks if a philo is dead, by checking the
 * 				death_flag.
 * 			3.	If there are no issues, print the state of the philo.
 * 			4.	Manual syncing is done by delaying odd philos and letting the
 * 				even philos eat first.
 * 			5.	During this period, philos will try and grab forks to eat,
 * 				handled by queue_forks().
 * 
 * @param philo	The t_philo struct, representing the philosopher
 */

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
