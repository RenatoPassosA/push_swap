/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:01 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:03 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst)
		return (NULL);
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	*lst = NULL;
	return (*lst);
}

static t_list	*get_sub(t_list *new_node, char *s, int index, char c)
{
	char	*sub;

	sub = substr((char *)s, index, c);
	new_node = lst_new(ft_atol(sub));
	free(sub);
	return (new_node);
}

t_list	*ft_splitlst(char *s, char c, int index)
{
	t_list	*head;
	t_list	*current;
	t_list	*new_node;

	head = NULL;
	current = NULL;
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			new_node = get_sub(new_node, s, index, c);
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
