/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:29 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:31:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief	Checks if the input parameter only consists of digits from 0 to 9.
 * 
 * @param s A string
 * @return int 
 */

static int	ft_isnum(char *s)
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

/**
 * @brief	Checks the program's inputs, not including the program name.
 * 
 * @param argc The number of arguments
 * @param argv The arguments as an array of strings
 * @return int 
 */

static int	check_args(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' ||
		(ft_strlen(argv[i]) == 1 && argv[i][0] == '0') ||
		ft_isnum(argv[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief	First checks if the inputs are valid, then initialises a t_data
 * 			struct, and depending if the optional argument is provided,
 * 			initialises it accordingly.
 * 
 * @param argc The number of arguments
 * @param argv The arguments as an array of strings, program name not included
 * @return t_data* 
 */

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
	printf("%s%s%s\n", C_G, "HERE", C_NC);
	return (ret);
}

/**
 * @brief	Initialises a new t_data struct and returns a pointer to it.
 * 			The optional argument is not assigned here.
 * 
 * @param argv	The arguments as an array of strings, already checked for
 * 				validity
 *
 * @return t_data*
 */

t_data	*ft_data_new(char **argv)
{
	t_data	*ret;

	ret = malloc(sizeof(t_data));
	if (ret == NULL)
		return (NULL);
	ret->num_philo = (size_t)ft_atoi(argv[0]);
	ret->t_2die = (size_t)ft_atoi(argv[1]);
	ret->t_2eat = (size_t)ft_atoi(argv[2]);
	ret->t_2slp = (size_t)ft_atoi(argv[3]);
	return (ret);
}

/**
 * @brief	Frees the t_data struct passed as the parameter.
 * 
 * @param dat 
 */

void	ft_data_del(t_data *dat)
{
	free(dat);
}
