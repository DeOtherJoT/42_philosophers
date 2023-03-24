/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:30:53 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:30:55 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_base	*init_base(t_data *input)
{
	t_base	*ret;
	size_t	i;

	ret = malloc(sizeof(t_base));
	ret->start_time = gettime_ms();
	ret->data = input;
	ret->death_flag = 0;
	ret->fork_stat = ft_calloc(input->num_philo, sizeof(int));
	ret->fork_mtx = malloc(sizeof(pthread_mutex_t) * input->num_philo);
	i = -1;
	while (++i < input->num_philo)
		pthread_mutex_init(&(ret->fork_mtx[i]), NULL);
	pthread_mutex_init(&(ret->death_mtx), NULL);
	pthread_mutex_init(&(ret->write_mtx), NULL);
	pthread_mutex_init(&(ret->fstate_mtx), NULL);
	return (ret);
}

t_philo	*init_philos(t_data *input)
{
	t_base	*base_data;
	t_philo	*ret;
	size_t	i;

	base_data = init_base(input);
	i = -1;
	ret = malloc(sizeof(t_philo) * input->num_philo);
	while (++i < input->num_philo)
	{
		(ret)[i].id = i;
		(ret)[i].l_fork = i;
		(ret)[i].r_fork = (i + 1) % input->num_philo;
		(ret)[i].num_ate = 0;
		(ret)[i].to_die = 0;
		(ret)[i].base = base_data;
	}
	return (ret);
}

void	del_base(t_base *base, size_t num_philo)
{
	size_t	i;

	ft_data_del(base->data);
	free(base->fork_stat);
	i = -1;
	while (++i < num_philo)
		pthread_mutex_destroy(&(base->fork_mtx[i]));
	free(base->fork_mtx);
	pthread_mutex_destroy(&(base->death_mtx));
	pthread_mutex_destroy(&(base->write_mtx));
	pthread_mutex_destroy(&(base->fstate_mtx));
	free(base);
}

void	del_philos(t_philo **philos, size_t num_philo)
{
	size_t	i;

	if (philos[0]->base != NULL)
		del_base(philos[0]->base, num_philo);
	i = -1;
	free(*philos);
}
