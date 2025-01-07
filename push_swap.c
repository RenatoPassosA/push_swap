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
            else if (save_index == -1)
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


int check_errors()
{



    
}

int main(int ac, char **av)
{
    int index;
    int splitindex;
    char *inputs;
    s_list *list_a;
    s_list *list_b;

    list_b = NULL;
    splitindex = -1;
    index = 2;
    if (ac == 1)
    {
        putstr("Error\n");
        return (0);
    }
    else
    {
        inputs = av[1];
        set_index(&list_a);
        if (ordered(&list_a))
            return (0);
        if (size(&list_a) < 6)
            small_numbers(&list_a, &list_b);
        else
            radix(&list_a, &list_b);
    }
    return (0);
}

    /*while(list_a)
        {
            printf("%ld\n",list_a->content);
            list_a = list_a->next;
        }*/