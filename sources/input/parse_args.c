#include "../../includes/philo.h"

t_data	*parse_args(int argc, char **argv)
{
	t_data	*ret;

	if (check_args(argc, argv) == FALSE)
		return (NULL);
	ret = ft_data_new(argv);
	if (argc == 4)
		ret->num_2eat = 0;
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

	ret = malloc(sizeof(t_data));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		if (ft_atoi(argv[i]) < 1)
			return (NULL);
	}
	ret->num_philo = (size_t)ft_atoi(argv[0]);
	ret->t_2die = (size_t)ft_atoi(argv[1]);
	ret->t_2eat = (size_t)ft_atoi(argv[2]);
	ret->t_2slp = (size_t)ft_atoi(argv[3]);
	return (ret);
}

void	ft_data_del(t_data *dat)
{
	free(dat);
}

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (ft_isnum(argv[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE); 
}