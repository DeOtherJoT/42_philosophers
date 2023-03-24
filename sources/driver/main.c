/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:05 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:31:06 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Note that inputs are in milliseconds.
*/

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (error_msg("Incorrect number of arguments", -1));
	data = parse_args(argc - 1, argv + 1);
	if (data == NULL)
		return (error_msg("Invalid arguments", -2));
	dinner_table(data);
	return (0);
}
