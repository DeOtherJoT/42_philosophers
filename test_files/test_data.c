#include "../includes/philo.h"
#include <stdio.h>


// Data printer

void	print_data(t_data *data)
{
	printf("Number of philo       : %zu\n", data->num_philo);
	printf("Time to die in ms     : %zu\n", data->t_2die);
	printf("Time to eat in ms     : %zu\n", data->t_2eat);
	printf("Time to slp in ms     : %zu\n", data->t_2eat);
	printf("Number of time to eat : %zu\n", data->num_2eat);
}

// Tester driver

int	main(int argc, char **argv)
{
	t_data	*ret;

	printf("%s===== BEGIN =====%s\n", C_G, C_NC);
	ret = parse_args(argc - 1, argv + 1);
	printf("%s===== DONE PARSE =====%s\n", C_G, C_NC);
	print_data(ret);
	printf("%s===== DONE =====%s\n", C_G, C_NC);
}