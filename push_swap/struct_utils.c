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

int    size(s_list **head)
{
    int count = 1;
    s_list *nodes;

    nodes = *head;
    
    if (!nodes)
        return (0);
    while(nodes->next)
    {
        count++;
        nodes = nodes->next;
    }
    return (count);
}

int find_pivot(s_list **head)
{
    s_list *current = *head;
    int amount;
    int up;
    int down;

    amount = 0;
    up = 0;
    down = 0;
    while(current)
    {
        amount += (current->content);
        current = current->next;
    }
    amount /= size(head);
    up = amount;
    down = amount;
    while(1)
    {
        current = *head;
        up++;
        down--;
        while (current)
        {
            if (current->content == up)
                return (up);
            if (current->content == down)
                return (down);
            current = current->next;
        }
    }
    return (0);
}

int ordered(s_list **head)
{
    s_list *current;
    
    current = *head;
    while (current && current->next)
    {
        if (current->content < current->next->content)
            current = current->next;
        else
            return(0);   
    }
    return(1);
}