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

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				s_list;


s_list *lst_new(int n);
void add_back(s_list **head, s_list *new);
int    size(s_list **head);
int find_pivot(s_list **head);
int ordered(s_list **head);