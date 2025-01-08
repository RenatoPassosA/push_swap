/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:45:50 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:20 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(long n)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = n;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	size(t_list **head)
{
	int		count;
	t_list	*nodes;

	count = 1;
	nodes = *head;
	if (!nodes)
		return (0);
	while (nodes->next)
	{
		count++;
		nodes = nodes->next;
	}
	return (count);
}

void	set_index(t_list **head)
{
	t_list	*current;
	t_list	*ptr;
	int		i;
	int		min;

	i = 0;
	while (i < size(head))
	{
		current = *head;
		min = INT_MAX;
		while (current)
		{
			if (current->content < min && current->index == -1)
			{
				min = current->content;
				ptr = current;
			}
			current = current->next;
		}
		if (ptr == NULL)
			return ;
		ptr->index = i;
		ptr = NULL;
		i++;
	}
}

void	rotate_pos(t_list **a, int pos)
{
	int	range;

	if (size(a) == 4)
		range = 3;
	else if (size(a) == 5)
		range = 4;
	if (pos == 0)
		return ;
	if (pos <= 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos <= range)
		{
			rra(a);
			pos++;
		}
	}
}

int	ordered(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current && current->next)
	{
		if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
