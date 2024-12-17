#include "push_swap.h"

int	is_alpha (char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

}


int	check_char(char **arr)
{
	int	i;
	int	str_i;

	i = 0;
	str_i = 0;
	while(*arr[i] != '\0')
	{
		while(arr[i][str_i] != '\0')
		{
			if (arr[i][str_i] == '-' && !is_alpha(arr[i][str_i + 1]))
				return (0);
			else if (arr[i][str_i] == '+' && !is_alpha(arr[i][str_i + 1]))
				return (0);
			if (!is_alpha(arr[i][str_i]))
				return (0);
			str_i++;
		}
		i++;
	}
	return (1);
}