/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:09:40 by rpassos-          #+#    #+#             */
/*   Updated: 2024/12/11 14:09:42 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	int			content;
	int	index;
	struct s_list	*next;
}				s_list;

s_list *lst_new(int n);
void add_back(s_list **head, s_list *new);
int    size(s_list **head);
void set_index(s_list **head);
void sa(s_list **a);
void sb(s_list **b);
void ss(s_list **a, s_list **b);
void pa(s_list **a, s_list**b);
void pb(s_list **a, s_list**b);
void    ra(s_list **a);
void    rb(s_list **b);
void    rr(s_list **a, s_list **b);
void    rra(s_list **a);
void    rrb(s_list **b);
void    rrr(s_list **a, s_list **b);

