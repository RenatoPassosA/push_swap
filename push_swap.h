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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*lst_new(long n);
int					size(t_list **head);
void				set_index(t_list **head);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
char				*ft_strjoin(char *s1, char *s2);
int					check_char(char *str);
long				ft_atol(char *s);
size_t				ft_strlen(const char *str);
t_list				*ft_splitlst(char *s, char c, int index);
void				small_numbers(t_list **a, t_list **b);
void				rotate_pos(t_list **a, int pos);
int					ordered(t_list **head);
int					check_doubles(t_list **a);
void				putstr(char *str, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
t_list				*ft_lstclear(t_list **lst);

#endif
