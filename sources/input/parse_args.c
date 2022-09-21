#include "../../includes/philo.h"

t_data	*parse_args(int argc, char **argv)
{
	t_data	*ret;

	ret = ft_data_new(argv);
	if (argc == 4)
		ret->num_2eat = -1;
	else if (argc == 5)
	{
		ret->num_2eat = ft_atoi(argv[4]);
		if (ret->num_2eat < 1)
		{
			ft_data_del(ret);
			return (NULL);
		}
	}
	return (ret);
}

t_data	*ft_data_new(char **argv)
{
	t_data	*ret;
	size_t	i;
	int		temp;

	ret = malloc(sizeof(t_data));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (ft_atoi(argv[i]) < 1)
			return (NULL);
	}
	ret->num_philo = ft_atoi(argv[0]);
	ret->time_2die = ft_atoi(argv[1]);
	ret->time_2eat = ft_atoi(argv[2]);
	ret->time_2slp = ft_atoi(argv[3]);
	return (ret);
}