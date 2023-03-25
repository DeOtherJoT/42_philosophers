/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:43 by jthor             #+#    #+#             */
/*   Updated: 2023/03/24 15:31:44 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief	Basic string to int function
 * 
 */

int	ft_atoi(char *str)
{
	int	ret;
	int	neg;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	neg = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	ret = 0;
	while (*str && (*str >= '0' || *str <= '9'))
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * neg);
}

/**
 * @brief	Basic strlen function
 * 
 */

size_t	ft_strlen(char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

/**
 * @brief	Prints an error message and returns the error number passed as an
 * 			argument.
 * 
 */

int	error_msg(char *str, int err_no)
{
	write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (err_no);
}

/**
 * @brief	Basic calloc function
 * 
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*retptr;
	size_t	i;

	retptr = (void *)malloc(count * size);
	if (!retptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)retptr)[i] = 0;
		i++;
	}
	return (retptr);
}

/**
 * @brief	Returns how many milliseconds has passed since January 1st 1970
 * 
 */

size_t	gettime_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}
