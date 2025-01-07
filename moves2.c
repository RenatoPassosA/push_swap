#include "push_swap.h"

void    ra(s_list **a)
{
    s_list  *first;
    s_list  *last;
    
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
    putstr("rb");
    putstr("\n");
}

void    rr(s_list **a, s_list **b)
{
    ra(a);
    rb(b);
    putstr("rr");
    putstr("\n");
}

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
    }
    
    last = *a;
    while(last->next)
        last = last->next;
    first->next = NULL;
    last->next = temp;
    *a = last;
    putstr("rra");
    putstr("\n");
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
    }
    last = *b;
    while(last->next)
        last = last->next;
    first->next = NULL;
    last->next = temp;
    *b = last;
    putstr("rrb");
    putstr("\n");
}