#include "../../includes/philo.h"

/*
Introduction to multi-thread programming with the use of mutex, in the form
of the Dining Philosophers Problem.

Input : 1 , 2 , 3 , 4 , [5]
	1. num_of_philo
	2. time_to_die
	3. time_to_eat
	4. time_to_sleep
	5. number_of_times_each_philo_must_eat [optional]
*/

int	main(int argc, char **argv)
{
	t_data	*args;

	if (argc < 5 || argc > 6)
	 	return (error_msg("Incorrect number of arguments\n"));
	args = parse_args(argc - 1, argv + 1);
	if (args == NULL)
		return (error_msg("Invalid arguments\n"));
	if (think_tank(args) == NULL)
		return (error_msg("Problem\n"));
	ft_data_del(args);
	return (0);
}