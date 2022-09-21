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

	if (argc != 5 || argc != 6)
	 	return (error_msg("Incorrect number of arguments")) ;
	// if (argc == 4)
	// {
	// 	args = parse_args(argv);
	// 	args->num_2eat = -1;
	// }
	// else if (argc == 5)
	// {
	// 	args = parse_args(argv);
	// 	args->num_2eat = ft_atoi(argv[4]);
	// 	if (args->num_2eat < 1)
	// 		return(exit_error(args, "Philos must eat at least once."));
	// }
	args = parse_args(argc - 1, argv + 1);
	think_tank(args);
	ft_data_del(args);
	return (0);
}