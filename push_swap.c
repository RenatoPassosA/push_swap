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

static int	get_num_bites(int a)
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

static void	radix(t_list **a, t_list **b)
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

static int	check_error_call_algorithym(char *inputs, t_list *list_a,
		t_list *list_b)
{
	if (!list_a || check_doubles(&list_a) || !check_char(inputs))
	{
		putstr("Error", 2);
		putstr("\n", 1);
		return (0);
	}
	set_index(&list_a);
	if (ordered(&list_a))
		return (0);
	if (size(&list_a) < 6)
		small_numbers(&list_a, &list_b);
	else
		radix(&list_a, &list_b);
	ft_lstclear(&list_a);
	return (1);
}

static char	*call_join(char *inputs, char **av, int ac)
{
	int		index;
	char	*temp;

	index = 1;
	while (++index < ac)
	{
		temp = inputs;
		inputs = ft_strjoin(inputs, av[index]);
		if (index >= 3)
			free(temp);
	}
	return (inputs);
}

int	main(int ac, char **av)
{
	int		splitindex;
	char	*inputs;
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	splitindex = -1;
	if (ac <= 2)
		putstr("Error\n", 2);
	else
	{
		inputs = av[1];
		inputs = call_join(inputs, av, ac);
		list_a = ft_splitlst(inputs, ' ', splitindex);
		check_error_call_algorithym(inputs, list_a, list_b);
		free(inputs);
	}
	return (0);
}
