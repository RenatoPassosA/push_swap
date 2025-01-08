/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:25 by rpassos-          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:27 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*new_first;
	t_list	*temp;
	t_list	*hold;

	if (size(a) <= 1)
		return ;
	temp = *a;
	new_first = temp->next;
	hold = new_first->next;
	new_first->next = temp;
	temp->next = hold;
	*a = new_first;
	putstr("sa", 1);
	putstr("\n", 1);
}

void	sb(t_list **b)
{
	t_list	*new_first;
	t_list	*temp;
	t_list	*hold;

	if (size(b) <= 1)
		return ;
	temp = *b;
	new_first = temp->next;
	hold = new_first->next;
	new_first->next = temp;
	temp->next = hold;
	*b = new_first;
	putstr("sb", 1);
	putstr("\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	putstr("ss", 1);
	putstr("\n", 1);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*first_b;

	if (!(*b))
		return ;
	first_b = *b;
	*b = first_b->next;
	first_b->next = *a;
	*a = first_b;
	putstr("pa", 1);
	putstr("\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*first_a;

	if (!(*a))
		return ;
	first_a = *a;
	*a = first_a->next;
	first_a->next = *b;
	*b = first_a;
	putstr("pb", 1);
	putstr("\n", 1);
}
