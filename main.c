/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:44:54 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:44:54 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, char stack_name)
{
    ft_printf("Stack %c details:\n", stack_name);
    while (stack != NULL)
    {
        ft_printf("number: %d, index: %d, push_cost: %d, above_median: %d, cheapest: %d\n",
            stack->number, stack->index, stack->push_cost, stack->above_median, stack->cheapest);
        stack = stack->next;
    }
}

void	push_swap(char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size_stack;

	a = NULL;
	b = NULL;
	init_validations(&a, argv);
	if (already_sorted(a))
		print_info(INFO_1);
	else
	{
		size_stack = ft_stack_len(a);
		if (size_stack == 3)
			sort_three(&a);
		else if (size_stack == 2)
			swap_change(&a, 'a');
		else
			sort_stack(&a, &b);
		print_stack(a, 'a');
	}
	free_all(&a);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);

	}
	else
		print_error(ERROR_0);
	return (0);
}
