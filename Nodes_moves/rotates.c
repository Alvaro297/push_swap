/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:49:02 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:49:02 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotates_swap(t_node **stack, char c)
{
	t_node	*current;
	t_node	*first_target;
	int		first_number;
	bool	first_cheapest;
	int		first_push_cost;

	if (!(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	first_number = current->number;
	first_target = current->target;
	first_cheapest = current->cheapest;
	first_push_cost = current->push_cost;
	while (current->next != NULL)
	{
		set_values(current, 1);
		current = current->next;
	}
	current->number = first_number;
	current->target = first_target;
	current->cheapest = first_cheapest;
	current->push_cost = first_push_cost;
	if (c != 'r')
		ft_printf("r%c\n", c);
}

void	rotates_both(t_node **stack_a, t_node **stack_b)
{
	rotates_swap(stack_a, 'r');
	rotates_swap(stack_b, 'r');
	ft_printf("rr");
}

void	reverse_rotate_swap(t_node **stack, char c)
{
	t_node	*current;
	t_node	*first_target;
	int		first_number;
	bool	first_cheapest;
	int		first_push_cost;

	if (!(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	first_number = current->number;
	first_target = current->target;
	first_cheapest = current->cheapest;
	first_push_cost = current->push_cost;
	while (current->prev != NULL)
	{
		set_values(current, 2);
		current = current->prev;
	}
	current->number = first_number;
	set_final_values(current, first_target, first_cheapest, first_push_cost);
	if (c != 'r')
		ft_printf("rr%c\n", c);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_swap(stack_a, 'r');
	reverse_rotate_swap(stack_b, 'r');
	ft_printf("rr");
}
