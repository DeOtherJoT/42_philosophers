#include "../../includes/philo.h"

// Decides which mode to run, depending on whther the optional num_2eat
// is in effect.

int	think_tank(t_data *input, int argc)
{
	t_philo	*philos;
	int		i;

	if (argc == 5) // run until a philo dies
	{
		while (1)
		{
			if (dinner_table(philos, input) == 0);
				return (0);
		}
	}
	else // run until philo dies or num_2eat is fulfilled
	{
		i = 0;
		while (i < input->num_2eat)
		{
			if (dinner_table(philos, input) == 0)
				return (0);
			i++;
		}
	}
	return (1); // no problem found
}