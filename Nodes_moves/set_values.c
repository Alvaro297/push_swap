/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:49:07 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:49:07 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_values(t_node *stack, int i)
{
	if (i == 1)
	{
		stack->number = stack->next->number;
		stack->target = stack->next->target;
		stack->cheapest = stack->next->cheapest;
		stack->push_cost = stack->next->push_cost;
	}
	else
	{
		stack->number = stack->prev->number;
		stack->target = stack->prev->target;
		stack->cheapest = stack->prev->cheapest;
		stack->push_cost = stack->prev->push_cost;
	}
}

void	set_final_values(t_node *stack, t_node *first_target,
		bool first_cheapest, int first_push_cost)
{
	stack->target = first_target;
	stack->cheapest = first_cheapest;
	stack->push_cost = first_push_cost;
}
