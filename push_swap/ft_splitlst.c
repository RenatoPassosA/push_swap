
#include "push_swap.h"

static char	*substr(char *s, int index, char c)
{
	char	*sub;
	int		subindex;
	int		size;

	size = 0;
	subindex = index;
	while (!(s[index] == c || s[index] == '\0'))
	{
		size++;
		index++;
	}
	sub = (char *)malloc(sizeof(char) * size + 1);
	if (!sub)
		return (NULL);
	index = subindex;
	subindex = 0;
	while (subindex < size)
		sub[subindex++] = s[index++];
	sub[subindex] = '\0';
	return (sub);
}

s_list	*ft_splitlst(char *s, char c)
{
	s_list	*head;
	s_list	*current;
	s_list	*new_node;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	head = NULL;
	current = NULL;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			new_node = lst_new(ft_atol(substr((char *)s, index, c)));
			if (!head) //salvar a referencia do primeiro nó da lista
				head = new_node;
			else
				current->next = new_node;//adiciona o nó no final da lista
			current = new_node; //iteração sobre a lista
			//current e head apontam pra mesma referencia no inicio. após o current itera e adiciona valores a lista
			while (!(s[index] == c || s[index] == '\0'))
				index++;
		}
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (head);
}