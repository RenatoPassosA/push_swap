
#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int	ft_atol(char *s)
{
	int			minus_sign;
	long int	result;

	minus_sign = 0;
	result = 0;
	while (*s)
	{
		while (*s == 32 || (*s >= 9 && *s <= 13))
			s++;
		if (*s == '+' || *s == '-')
		{
			if (*s == '-')
				minus_sign = 1;
			s++;
		}
		while (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			s++;
		}
		if (minus_sign)
			return (result * -1);
		return (result);
	}
	return (0);
}
