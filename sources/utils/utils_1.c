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