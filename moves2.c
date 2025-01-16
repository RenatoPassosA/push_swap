/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:24:40 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:24:42 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (size(a) < 2)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	putstr("ra");
	putstr("\n");
}

void	rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (size(b) < 2)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	putstr("rb");
	putstr("\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	putstr("rr");
	putstr("\n");
}

void	rra(t_list **a)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp;

	first = *a;
	temp = *a;
	while (first->next)
	{
		if (!first->next->next)
			break ;
		first = first->next;
	}
	last = *a;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = temp;
	*a = last;
	putstr("rra");
	putstr("\n");
}

void	rrb(t_list **b)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp;

	first = *b;
	temp = *b;
	while (first->next)
	{
		if (!first->next->next)
			break ;
		first = first->next;
	}
	last = *b;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = temp;
	*b = last;
	putstr("rrb");
	putstr("\n");
}
