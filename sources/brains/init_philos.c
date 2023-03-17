#include "../../includes/philo.h"

t_base	*init_base(t_data *input)
{
	t_base	*ret;
	int		i;

	ret = malloc(sizeof(t_base));
	ret->data = input;
	ret->death_flag = 0;
	ret->fork_stat = ft_calloc(input->num_philo, sizeof(int));
	ret->philo_stat = ft_calloc(input->num_philo, sizeof(int));
	ret->fork_mtx = malloc(sizeof(pthread_mutex_t) * input->num_philo);
	i = -1;
	while (++i < input->num_philo)
		pthread_mutex_init(&(ret->fork_mtx[i]), NULL);
	pthread_mutex_init(&(ret->state_mtx), NULL);
	pthread_mutex_init(&(ret->write_mtx), NULL);
}

void	init_philos(t_philo **philos, t_data *input)
{
	t_base	*base_data;
	int		i;

	base_data = init_base(input);
	i = -1;
	philos = malloc(sizeof(t_philo *) * input->num_philo);
	while (++i < input->num_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->num_id = i;
		philos[i]->l_fork = i;
		philos[i]->r_fork = (i + 1) % input->num_philo;
		philos[i]->num_ate = 0;
		philos[i]->to_die = 0;
		philos[i]->base = base_data;
	}
}

void	del_base(t_base *base, size_t num_philo)
{
	int	i;

	ft_data_del(base->data);
	free(base->fork_stat);
	free(base->philo_stat);
	i = -1;
	while (++i < num_philo)
		pthread_mutex_destroy(&(base->fork_mtx[i]));
	free(base->fork_mtx);
	pthread_mutex_destroy(&(base->state_mtx));
	pthread_mutex_destroy(&(base->write_mtx));
	free(base);
}

void	del_philos(t_philo **philos, size_t num_philo)
{
	int	i;

	del_base(philos[0]->base, num_philo);
	i = -1;
	while (++i < num_philo)
		free(philos[i]);
	free(philos);
}