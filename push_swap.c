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
    char *inputs;
    s_list *list_a;
    s_list *list_b;

    index = 2;
    if (ac == 1)
    {
        printf("Error - (nenhum argumento)\n");
        return (0);
    }
    else
    {
        inputs = av[1];
        while (index < ac)
        {
            inputs = ft_strjoin(inputs, av[index]); //ATÉ AQUI OK
            index++;
        }
        printf("------%s--------\n", inputs);
        if (!check_char(inputs))//verificação de caracteres
        {
            printf("Error - (caracter como parametro)\n");
            return (0);
        }
        list_a = ft_splitlst(inputs, ' ');//criação da lista encadeada
        if (!list_a)
        {
            printf("Error - (numero > INT_MAX)\n");
            return (0);
        }
        list_b = NULL;
        if (check_doubles(&list_a))
        {
            printf("Error - (numero duplicado)\n");
            return(0);
        }
        set_index(&list_a);//inicialização dos indices
        small_numbers(&list_a, &list_b); //chamada dos algoritmos
    }
    
    

   /*while(list_a)
     {
        printf("C: %d\n", list_a->content);
        //printf("I: %d\n", list_a->index);
        list_a = list_a->next;
     }
    printf("------------\n");*/
   

    return (0);

}

