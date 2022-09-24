#include "../../includes/philo.h"

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
	while (*str >= '0' || *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * neg);
}

size_t	ft_strlen(char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	error_msg(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}