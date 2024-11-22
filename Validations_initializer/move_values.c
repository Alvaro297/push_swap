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

void	set_cheapest(t_node *stack)
{
	long	best_match_value;
	t_node	*best_match_node;

	if (NULL == stack)
		return ;
	best_match_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < best_match_value)
		{
			best_match_value = stack->push_cost;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
}

t_node	*ischeapest(t_node	*stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		if (current ->cheapest)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

void	move_values(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	int		cheapest_number;
	int		target_number;

	cheapest = ischeapest(*stack_b);
	cheapest_number = cheapest->number;
	target_number = cheapest->target->number;
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while ((*stack_a)-> number != target_number
			&& (*stack_b)-> number != cheapest_number)
			rotate_both(stack_a, stack_b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
	{
		while ((*stack_a)-> number != target_number
			&& (*stack_b)-> number != cheapest_number)
			reverse_rotate_both(stack_a, stack_b);
	}
	finish_rotation(stack_b, 'b');
	finish_rotation(stack_a, 'a');
	push_x(stack_b, stack_a, 'a');
}

void	finish_rotation(t_node **stack, char stack_name)
{
	t_node	*top_node;

	if (stack_name == 'b')
		top_node = ischeapest(*stack);
	else if (stack_name == 'a')
		top_node = ischeapest(*stack)-> target;
	while (*stack != top_node)
	{
		if (top_node->above_median)
			rotates_swap(stack, stack_name);
		else
			reverse_rotates_swap(stack, stack_name);
		if (stack_name == 'b')
			top_node = ischeapest(*stack);
		else if (stack_name == 'a')
			top_node = ischeapest(*stack)-> target;
	}
}
