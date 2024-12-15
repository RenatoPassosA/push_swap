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

    if (size(a) <= 1)
        return;
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

    if (size(b) <= 1)
        return;
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
    if (!(*b))
        return ;
    s_list *first_b;

    first_b = *b;
    *b = first_b->next;
    first_b->next = *a;
    *a = first_b;
}

void pb(s_list **a, s_list**b)
{
    if (!(*a))
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
    
    if (size(a) < 2)
        return ;
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
    
    if (size(b) < 2)
        return ;
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

//QUICK SORT

void    quick(s_list **head1, s_list **head2, int check, char operator)
{
    int pivot;
    int stack_size;
    s_list *stack;
    
    pivot = find_pivot(head1);
    printf("PIVO:%d\n", pivot);
    stack = *head1;
    stack_size = size(head1);
    while(stack_size > 0)
    {
        stack = *head1;
        if (operator == '<')
        {
            if (stack->content < pivot)
            {
                pb(head1, head2);
            }
            else
                ra(head1); //aqui funciona - testei com mais ifs iguais a esse e responde certo
            stack_size--;
        }
        else
         {
            if (stack->content > pivot)
            {
                pb(head1, head2);
            }
            else
                ra(head1); //aqui funciona - testei com mais ifs iguais a esse e responde certo
            stack_size--;
        
        //tornar esse if recursivo
         }
    check++;
    if (ordered(head1) && ordered(head2))
    {
        printf("FOI");
        return ;
    }
        if (check % 2 == 0)
            quick(head1, head2, check, '<');
        else
            quick(head2, head1, check, '>');
    }

   /*s_list *aa = *head1;
    s_list *bb = *head2;
    
    while(aa)
    {
        printf("%d\n", aa->content);
        aa = aa->next;
    }
    printf("------------\n");
    while(bb)
    {
        printf("%d\n", bb->content);
        bb = bb->next;
    }

    pivot = find_pivot(head2);
    printf("PIVO:%d\n", pivot);
    stack = *head2;
    stack_size = size(head2);
    while(stack_size > 0)
    {
        
        if (stack->content < pivot)
        {
            pb(head2, head1);
            stack = *head2;
        }
        else
            ra(head2); //aqui funciona - testei com mais ifs iguais a esse e responde certo
        stack_size--;
        //tornar esse if recursivo
    }
    check++;

while(aa)
    {
        printf("%d\n", aa->content);
        aa = aa->next;
    }
    printf("------------\n");
    while(bb)
    {
        printf("%d\n", bb->content);
        bb = bb->next;
    }*/
}



int main(void)
{
   
    
    s_list *head1 = lst_new(2);
    s_list *b = lst_new(3);
    s_list *c = lst_new(20);
    s_list *d = lst_new(1);
    s_list *e = lst_new(6);
    s_list *f = lst_new(4);
   

    head1->next = b; 
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    s_list *head2 = NULL;

    quick(&head1, &head2, 0, '<');

    /*s_list *head2 = lst_new(10);
    s_list *b2 = lst_new(11);
    s_list *c2 = lst_new(12);
    s_list *d2 = lst_new(13);
    s_list *e2 = lst_new(14);
    s_list *f2 = lst_new(15);

    head2->next = b2; 
    b2->next = c2;
    c2->next = d2;
    d2->next = e2;
    e2->next = f2;*/

    //sa(&head1);
    //pb(&head1, &head2);
    //pb(&head1, &head2);
    //rb(&head2);
    //rra(&head2);

    // int a = size(&head1);
    //printf("%d", a);
   
    //int a = find_pivot(&head1);
    //printf("%d", a);

    //int a = ordered(&head1);
    //printf("%d", a);

    /*while(head1)
    {
        printf("%d\n", head1->content);
        head1 = head1->next;
    }
    printf("------------\n");
    while(head2)
    {
        printf("%d\n", head2->content);
        head2 = head2->next;
    }*/

    return (0);

}

