
#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return ((int)result * sign);
}
