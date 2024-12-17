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






int main(int ac, char **av)
{
    int index;
    int nums;
    char *inputs;
    char **arr;
    s_list *list_a;
    s_list *list_b;

    index = 1;
    nums = 1;
    if (ac == 1)
    {
        printf("Error - (nenhum argumento)\n");
        return (0);
    }
    else
    {
        while (index < ac)
        {
            inputs = ft_strjoin(inputs, av[index]);
            index++;
        }
        arr = ft_split(inputs, ' ');
        if (!check_char(arr))
            printf("Error - (caracter como parametro)\n");
        index = 0;
        while (*arr[index] != '\0')
            index++;
        list_a =  lst_new(ft_atol(arr[0]));
        while(nums <= index)
        {
            list_b = lst_new(ft_atol(arr[nums]));
            add_back(&list_a, list_b);
            nums++;
        }
        list_b = NULL;
    }
    
    set_index(&list_a);
    //radix(&list_a, &list_b);

   /*while(head1)
    {
        printf("I: %d\n", head1->index);
        head1 = head1->next;
    }
    printf("------------\n");
    while(head2)
    {
        printf("I: %d\n", head2->index);
        head2 = head2->next;
    }*/

    return (0);

}

