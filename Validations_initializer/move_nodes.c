/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:12 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:12 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cheapest(t_node *b)
{
	long		best_match_value;
	t_node		*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	smallest_to_top(t_node *stack)
{
	t_node	*smallest;
	int		smallest_number;

	smallest = find_smallest(stack);
	smallest_number = smallest -> number;
	if (smallest -> above_median)
		while (stack ->number != smallest_number)
			rotates_swap(&stack, 'a');
	else
		while (stack ->number != smallest_number)
			reverse_rotate_swap(&stack, 'a');
}
