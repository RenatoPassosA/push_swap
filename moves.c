#include "push_swap.h"

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
    putstr("sa");
    putstr("\n");
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
    putstr("sb");
    putstr("\n");
}

void ss(s_list **a, s_list **b)
{
    sa(a);
    sb(b);
    putstr("ss");
    putstr("\n");
}

void pa(s_list **a, s_list**b)
{
    if (!(*b))
        return ;
    s_list *first_b;

    first_b = *b;
    *b = first_b->next;
    first_b->next = *a;
    *a = first_b;
    putstr("pa");
    putstr("\n");
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
    putstr("pb");
    putstr("\n");
}