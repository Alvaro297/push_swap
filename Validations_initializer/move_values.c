/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:17 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:17 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ischeapest(t_node	*stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		if (current ->cheapest == 1)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

void	move_values(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	long	cheapest_number;
	long	target_number;

	cheapest = ischeapest(*stack_b);
	cheapest_number = cheapest->number;
	target_number = cheapest->target->number;
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while ((*stack_a)-> number != target_number
			&& (*stack_b)-> number != cheapest_number)
			rotates_both(stack_a, stack_b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
	{
		while ((*stack_a)-> number != target_number
			&& (*stack_b)-> number != cheapest_number)
			reverse_rotate_both(stack_a, stack_b);
	}
	finish_rotation(stack_a, stack_b, 'b');
	finish_rotation(stack_a, stack_b, 'a');
	push_x(stack_b, stack_a, 'a');
}

void	finish_rotation(t_node **stack_a, t_node **stack_b, char stack_name)
{
	t_node	**stack;
	t_node	*top_node;

	if (stack_name == 'b')
	{
		stack = stack_b;
		top_node = ischeapest(*stack_b);
	}
	else
	{
		stack = stack_a;
		top_node = ischeapest(*stack_b)->target;
	}
	finish_rotation2(stack, stack_b, top_node, stack_name);
}

void	finish_rotation2(t_node **stack, t_node **stack_b,
			t_node *top_node, char stack_name)
{
	while ((*stack)->number != top_node->number)
	{
		if (top_node->above_median)
			rotates_swap(stack, stack_name);
		else
			reverse_rotate_swap(stack, stack_name);
		if (stack_name == 'b')
			top_node = ischeapest(*stack_b);
		else
		{
			get_target_node(*stack, *stack_b);
			top_node = ischeapest(*stack_b)->target;
		}
	}
}
