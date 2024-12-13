/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:09:49 by rpassos-          #+#    #+#             */
/*   Updated: 2024/12/13 19:45:44 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAPS

void sa(s_list **a)
{
    s_list *new_first;
    s_list *temp;
    s_list  *hold;

    temp = *a;
    new_first = temp->next;
    hold = new_first->next;
    new_first->next = temp;
    temp->next = hold;
    *a = new_first; 
}

void sb(s_list **b)
{
    s_list *new_first;
    s_list *temp;
    s_list  *hold;

    temp = *b;
    new_first = temp->next;
    hold = new_first->next;
    new_first->next = temp;
    temp->next = hold;
    *b = new_first; 
}

void ss(s_list **a, s_list **b)
{
    sa(a);
    sb(b);
}

//PUSHS

void pa(s_list **a, s_list**b)
{
    if (!b)
        return ;
    s_list *first_b;

    first_b = *b;
    *b = first_b->next;
    first_b->next = *a;
    *a = first_b;
}

void pb(s_list **a, s_list**b)
{
    if (!a)
        return ;
    s_list *first_a;

    first_a = *a;
    *a = first_a->next;
    first_a->next = *b;
    *b = first_a;
}

//ROTATES

void    ra(s_list **a)
{
    s_list  *first;
    s_list  *last;
    
    first = *a;
    *a = first->next; //o primeiro nó da lista vira o segundo
    first->next = NULL;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first; //após o ultimo adiciono o primeiro
}

void    rb(s_list **b)
{
    s_list  *first;
    s_list  *last;
    
    first = *b;
    *b = first->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
}

void    rr(s_list **a, s_list **b)
{
    ra(a);
    rb(b);
}

//REVERSE ROTATES

void    rra(s_list **a)
{
    s_list  *first;
    s_list  *last;
    s_list  *temp;
 
    first = *a;
    temp = *a;
    while(first->next)
    {
        if (!first->next->next)
            break;
        first = first->next;
    }//pegou o penultimo
    
    last = *a;
    while(last->next)
        last = last->next;//pegou o ultimo
    first->next = NULL;
    last->next = temp;
    *a = last;
}

void    rrb(s_list **b)
{
    s_list  *first;
    s_list  *last;
    s_list  *temp;
 
    first = *b;
    temp = *b;
    while(first->next)
    {
        if (!first->next->next)
            break;
        first = first->next;
    }//pegou o penultimo
    
    last = *b;
    while(last->next)
        last = last->next;//pegou o ultimo
    first->next = NULL;
    last->next = temp;
    *b = last;
}

void    rrr(s_list **a, s_list **b)
{
    rra(a);
    rrb(b);
}



int main(void)
{
    //0,5,2,6,4,8
    
    s_list *head1 = lst_new(9);
    s_list *b = lst_new(5);
    s_list *c = lst_new(2);
    s_list *d = lst_new(6);
    s_list *e = lst_new(4);
    s_list *f = lst_new(8);

    head1->next = b; 
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    s_list *head2 = lst_new(10);
    s_list *b2 = lst_new(11);
    s_list *c2 = lst_new(12);
    s_list *d2 = lst_new(13);
    s_list *e2 = lst_new(14);
    s_list *f2 = lst_new(15);

    head2->next = b2; 
    b2->next = c2;
    c2->next = d2;
    d2->next = e2;
    e2->next = f2;

   

    //sa(&head);
    pa(&head1, &head2);
    //rra(&head2);
   

    while(head1)
    {
        printf("%d\n", head1->content);
        head1 = head1->next;
    }

    while(head2)
    {
        printf("%d\n", head2->content);
        head2 = head2->next;
    }

    return (0);



}
