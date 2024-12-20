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
    printf("sa");
    printf("\n");
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
    printf("sb");
    printf("\n");
}

void ss(s_list **a, s_list **b)
{
    sa(a);
    sb(b);
    printf("ss");
    printf("\n");
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
    printf("pa");
    printf("\n");
}

void pb(s_list **a, s_list**b) //pega primeiro elemento de a e coloca em b
{
    if (!(*a))
        return ;
    s_list *first_a;

    first_a = *a;
    *a = first_a->next;
    first_a->next = *b;
    *b = first_a;
    printf("pb");
    printf("\n");
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
    printf("ra");
    printf("\n");
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
    printf("rb");
    printf("\n");
}

void    rr(s_list **a, s_list **b)
{
    ra(a);
    rb(b);
    printf("rr");
    printf("\n");
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
    printf("rra");
    printf("\n");
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
    printf("rrb");
    printf("\n");
}

void    rrr(s_list **a, s_list **b)
{
    rra(a);
    rrb(b);
    printf("rrr");
    printf("\n");
}