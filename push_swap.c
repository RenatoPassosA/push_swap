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

int	get_num_bites(int a)
{
	int	bites;
	int	max_bites;

	bites = 0;
	max_bites = a;
	while (max_bites)
	{
		bites++;
		max_bites >>= 1;
	}
	return (bites);
}

void	radix(t_list **a, t_list **b)
{
	int	max_bits;
	int	bit;
	int	save_index;

	max_bits = get_num_bites(size(a) - 1);
	bit = 0;
	while (bit < max_bits)
	{
		save_index = -1;
		while (save_index != (*a)->index)
		{
			if ((((*a)->index >> bit) & 1) == 0)
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

int	check_error_call_algorithym(char *inputs, t_list *list_a, t_list *list_b)
{
	if (!list_a || check_doubles(&list_a) || !check_char(inputs))
	{
		putstr("Error split ou double ou check_char\n", 2);
		return (0);
	}
	set_index(&list_a);
	if (ordered(&list_a))
		return (0);
	if (size(&list_a) < 6)
		small_numbers(&list_a, &list_b);
	else
		radix(&list_a, &list_b);
	while (list_a)
	{
		printf("%ld\n", list_a->content);
		list_a = list_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		index;
	int		splitindex;
	char	*inputs;
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	splitindex = -1;
	index = 1;
	if (ac == 1)
	{
		putstr("Error\n", 2);
		return (0);
	}
	else
	{
		inputs = av[1];
		while (++index < ac)
			inputs = ft_strjoin(inputs, av[index]);
		list_a = ft_splitlst(inputs, ' ', splitindex);
		if (!check_error_call_algorithym(inputs, list_a, list_b))
			return (0);
	}
	return (0);
}
