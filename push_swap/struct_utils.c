/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:45:50 by rpassos-          #+#    #+#             */
/*   Updated: 2024/12/13 19:45:52 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
s_list *lst_new(int n)
{
    s_list *node;

    node = (s_list *)malloc(sizeof(s_list));
    if (!node)
        return(NULL);
    node->content = n;
    node->next = NULL;
    return(node);
}

void add_back(s_list **head, s_list *new)
{
    s_list *current;

    if (!head || new)
        return ;
    if (!*head)
    {
        *head = new;
        new->next = NULL;
        return ;
    }
    current = *head;
    while (current->next)
        current = current->next;
    current->next = new;
}
