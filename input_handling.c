
#include "push_swap.h"

int	is_digit (char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return (c == ' ');
}

int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && !is_digit(str[i + 1]))
			return (0);
		else if (!is_digit(str[i]) && !is_space(str[i]) && !(str[i] == '-' || str[i] == '+'))
			return (0);
		else if ((str[i] == '-' || str[i] == '+') && i > 0 && !is_space(str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(s_list **a)
{
	s_list *current;
	s_list	*next;
	s_list	*values;

	current = *a;
	values = (*a)->next;
	next = values;
	while(values)
	{
		while(next)
		{
			if (current->content == next->content)
				return(1);
			next = next->next;
		}
		current = current->next;
		values = values->next;
		next = values;
	}
	return(0);
}

void    putstr(char *str)
{
    int index = 0;
    while (str[index] != '\0')
    {
        write(1, &str[index], 1);
        index++;
    }
}