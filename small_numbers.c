/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:30 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:32 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	moves_tree(t_list **a, int pos, int n)
{
	if (pos == 0 && !ordered(a))
	{
		sa(a);
		ra(a);
	}
	else if (pos == 1)
	{
		sa(a);
		if (!ordered(a))
		{
			sa(a);
			ra(a);
		}
	}
	else if (pos == 2)
	{
		if ((*a)->index == n + 1)
			rra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

static void	three(t_list **a, int n)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = *a;
	while (current->index != n)
	{
		pos++;
		current = current->next;
	}
	moves_tree(a, pos, n);
}

static void	four(t_list **a, t_list **b)
{
	while ((*a)->index != 0)
		ra(a);
	pb(a, b);
	three(a, 1);
	pa(a, b);
}

static void	five(t_list **a, t_list **b)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = *a;
	while (current->index != 0)
	{
		pos++;
		current = current->next;
	}
	rotate_pos(a, pos);
	pb(a, b);
	pos = 0;
	current = *a;
	while (current->index != 1)
	{
		pos++;
		current = current->next;
	}
	rotate_pos(a, pos);
	pb(a, b);
	three(a, 2);
	pa(a, b);
	pa(a, b);
}

void	small_numbers(t_list **a, t_list **b)
{
	if (ordered(a))
		return ;
	if (size(a) == 2)
	{
		if (!ordered(a))
			ra(a);
	}
	else if (size(a) == 3)
		three(a, 0);
	else if (size(a) == 4)
		four(a, b);
	else if (size(a) == 5)
		five(a, b);
}
