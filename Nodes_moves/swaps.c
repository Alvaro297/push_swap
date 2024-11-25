/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:49:14 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:49:14 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_change(t_node **stack, char c)
{
	t_node	*tmp_target;
	long	tmp_number;
	bool	tmp_cheapest;
	int		tmp_push_cost;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp_number = (*stack)->number;
	tmp_target = (*stack)->target;
	tmp_cheapest = (*stack)->cheapest;
	tmp_push_cost = (*stack)->push_cost;
	(*stack)->number = (*stack)->next->number;
	(*stack)->push_cost = (*stack)->next->push_cost;
	(*stack)->target = (*stack)->next->target;
	(*stack)->cheapest = (*stack)->next->cheapest;
	(*stack)->next->number = tmp_number;
	(*stack)->next->push_cost = tmp_push_cost;
	(*stack)->next->target = tmp_target;
	(*stack)->next->cheapest = tmp_cheapest;
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	both_swap(t_node **stack_a, t_node **stack_b)
{
	swap_change(stack_a, 's');
	swap_change(stack_b, 's');
	ft_printf("ss\n");
}
