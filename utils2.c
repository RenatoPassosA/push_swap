
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

s_list	*ft_lstclear(s_list **lst)
{
	s_list	*temp;
	s_list	*current;

	if (!lst)
		return (NULL);
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*lst = NULL;
	return (*lst);
}

s_list	*ft_splitlst(char *s, char c, int index)
{
	s_list	*head;
	s_list	*current;
	s_list	*new_node;
	
	head = NULL;
	current = NULL;
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			new_node = lst_new(ft_atol(substr((char *)s, index, c)));
			if (new_node->content < INT_MIN || new_node->content > INT_MAX)
				return (ft_lstclear(&head));
			if (!head)
				head = new_node;
			else
				current->next = new_node;
			current = new_node;
			while (!(s[index] == c || s[index] == '\0'))
				index++;
		}
		if (s[index] == '\0')
			break ;
	}
	return (head);
}
