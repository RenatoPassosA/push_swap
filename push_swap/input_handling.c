
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
		else if (!is_digit(str[i]) && !is_space(str[i]) && str[i] != '+' && str[i] != '-')
			return (0);
		else if ((str[i] == '-' || str[i] == '+') && i > 0 && !is_space(str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(s_list **a)
{
	s_list *atual;
	s_list	*percorrer;

	atual = *a;
	(*a) = (*a)->next;//verificação começa no segundo elemento
	percorrer = *a;
	while((*a))//verifica item por item da lista
	{
		while(percorrer)//usado para iterar da onde tá até o final da lista
		{
			if (atual->content == percorrer->content)
				return(1);
			printf("---CHEKC VALUES %ld---\n", atual->content);

			percorrer = percorrer->next;
		}
		atual = atual->next;//o que vai ser comparado vai pra frente
		(*a) = (*a)->next;//a lista de fora vai pra frente
		percorrer = (*a);
	}
	return(0);
}

