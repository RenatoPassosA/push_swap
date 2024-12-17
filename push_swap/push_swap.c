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

int get_num_bites(int a)
{
    int bites = 0;
    int max_bites = a;
 
    while (max_bites)
    {
        bites++;
        max_bites >>= 1;
        
    }
    return (bites);
}

void    radix(s_list **a, s_list **b)
{
    int max_bits;
    int bit;
    int save_index;
  
    max_bits = get_num_bites(size(a) - 1);
    bit = 0;
    while (bit < max_bits)
    {
        save_index = -1;
        while(save_index != (*a)->index) 
        {
            if ((((*a)->index >> bit)& 1) == 0)
                pb(a, b);
            else if (save_index == -1) //guardo o index do primeiro elemento da rotação para ter uma condição de parada
            {
                save_index = (*a)->index;
                ra(a);
            }
            else
                ra(a);
         }
        while ((*b))
            pa(a, b);
        bit++;
    }
}





int main(void)
{
   
    
    s_list *head1 = lst_new(87);
    s_list *b = lst_new(-487);
    s_list *c = lst_new(1781);
    s_list *d = lst_new(-100);
    s_list *e = lst_new(101);
    s_list *f = lst_new(0);
    s_list *g = lst_new(1);
    
    head1->next = b; 
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    s_list *head2 = NULL;

    set_index(&head1);

    radix(&head1, &head2);



   
    /*printf("LISTA A:\n");
    while(head1)
    {
        printf("C: %d\n", head1->content);
        head1 = head1->next;
    }
    printf("------------\n");
    while(head2)
    {
        printf("C: %d\n", head2->content);
        head2 = head2->next;
    }*/

    

    while(head1)
    {
        printf("I: %d\n", head1->index);
        head1 = head1->next;
    }
    printf("------------\n");
    while(head2)
    {
        printf("I: %d\n", head2->index);
        head2 = head2->next;
    }

    return (0);

}

