/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:06 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:06 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medianvalue(t_node *stack_a, t_node *stack_b)
{
	int		len;
	t_node	*current;

	len = ft_stack_len(stack_a);
	current = stack_a;
	while (current != NULL)
	{
		if (current -> index <= len / 2)
			current -> above_median = true;
		else
			current -> above_median = false;
		current = current -> next;
	}
	current = stack_b;
	len = ft_stack_len(stack_b);
	while (current != NULL)
	{
		if (current -> index <= len / 2)
			current -> above_median = true;
		else
			current -> above_median = false;
		current = current -> next;
	}
}

void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	long	i;
	t_node	*current;

	while (stack_b != NULL)
	{
		i = LONG_MAX;
		current = stack_a;
		while (current != NULL)
		{
			if ((current -> number > stack_b -> number)
				&& (i > current -> number - stack_b -> number))
			{
				i = current -> number - stack_b -> number;
				stack_b -> target = current;
			}
			current = current -> next;
		}
		if (i == LONG_MAX)
			stack_b -> target = get_minimum_value(stack_a);
		stack_b = stack_b -> next;
	}
}

t_node	*get_minimum_value(t_node	*stack_x)
{
	long	i;
	t_node	*current;
	t_node	*minvalue;

	i = LONG_MAX;
	current = stack_x;
	while (current != NULL)
	{
		if (current -> number < i)
		{
			i = current->number;
			minvalue = current;
		}
		current = current -> next;
	}
	return (minvalue);
}

void	set_pricecost(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->index;
		if (!(stack_b->above_median))
			stack_b->push_cost = len_b - (stack_b->index);
		if (stack_b->target->above_median)
			stack_b->push_cost += stack_b->target->index;
		else
			stack_b->push_cost += len_a - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	init_values_stack(t_node *stack_a, t_node *stack_b)
{
	medianvalue(stack_a, stack_b);
	get_target_node(stack_a, stack_b);
	set_pricecost(stack_a, stack_b);
	set_cheapest(stack_b);
}
