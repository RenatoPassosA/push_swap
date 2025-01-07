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
}

void moves_tree(s_list **a, int  pos, int n)
{
    if (pos == 0 && !ordered(a))
        {
            sa(a);
            ra(a);
        }
        else if (pos == 1)
        {
            sa(a);
            if (!ordered(a))
            {
                sa(a);
                ra(a);
            }
        }
        else if (pos == 2)
        {
            if ((*a)->index == n + 1)
                rra(a);
            else
            {
                sa(a);
                rra(a);
            }
        }
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
    moves_tree(a, pos, n);        
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
