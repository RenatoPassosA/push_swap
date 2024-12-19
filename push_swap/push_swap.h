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
	long	content;
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
char	*ft_strjoin(const char *s1, const char *s2);
int	check_char(char *str);
int	ft_atol(char *s);
size_t	ft_strlen(const char *str);
s_list	*ft_splitlst(char *s, char c);
void small_numbers(s_list **a, s_list **b);
void three(s_list **a, int n);
void    four(s_list **a, s_list **b);
void    five(s_list **a, s_list **b);
void rotate_pos(s_list **a, int pos);
void    radix(s_list **a, s_list **b);
int ordered(s_list **head);
int	check_doubles(s_list **a);

