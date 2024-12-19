#include "push_swap.h"

void small_numbers(s_list **a, s_list **b)
{
    if (ordered(a))
        return ;
    if (size(a) == 2)
    {
        if (!ordered(a))
            ra(a);
    }
    else if (size(a) == 3)
        three(a, 0);
    else if (size(a) == 4)
        four(a, b);
    else if (size(a) == 5)
        five(a, b);
    else
        radix(a, b);
}

void three(s_list **a, int n)
{
    int pos;
    s_list *current;

    pos = 0;
    current = *a;
    while(current->index != n)
    {
        pos++;
        current = current->next;
    }
    if (pos == 0 && !ordered(a))
    {
        sa(a);
        ra(a);
    }
    else if (pos == 1)
    {
        if ((*a)->index == 1)
            sa(a);
        else
            ra(a);
    }
    else if (pos == 2)
    {
        if ((*a)->index == 1)
            rra(a);
        else
        {
            sa(a);
            rra(a);
        }
    }
}

void    four(s_list **a, s_list **b)
{
    while((*a)->index != 0)
        ra(a);
    pb(a, b);
    three(a, 1);
    pa(a, b);
}

void    five(s_list **a, s_list **b)
{   
    int pos;
    s_list *current;

    pos = 0;
    current = *a;
    while(current->index != 0)
    {
        pos++;
        current = current->next;
    }
    rotate_pos(a, pos);
    pb(a, b);
    pos = 0;
    current = *a;
    while(current->index != 1)
    {
        pos++;
        current = current->next;
    }
    rotate_pos(a, pos);
    pb(a, b);
    three(a, 2);
    pa(a, b);
    pa(a, b);
}

void rotate_pos(s_list **a, int pos)
{
    int range;

    if (size(a) == 4)
        range = 3;
    else if (size(a) == 5)
        range = 4;
    if (pos == 0)
        return ;
    if (pos <= 2)
    {
        while(pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        while(pos <= range)
        {
            rra(a);
            pos++;
        }
    }
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