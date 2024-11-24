/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:43 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:43 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **stack)
{
	int		a;
	int		b;
	int		c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && b < c && a < c)
		swap_change(stack, 'a');
	else if (a > b && b > c)
	{
		swap_change(stack, 'a');
		reverse_rotate_swap(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		rotates_swap(stack, 'a');
	else if (a < b && b > c && a < c)
	{
		swap_change(stack, 'a');
		rotates_swap(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_swap(stack, 'a');
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	while (find_min_index(*stack_a) != 0)
	{
		if (find_min_index(*stack_a) <= 2)
			rotates_swap(stack_a, 'a');
		else
			reverse_rotate_swap(stack_a, 'a');
	}
	push_x(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push_x(stack_b, stack_a, 'a');
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->index != find_min_index(*stack_a))
	{
		if (find_min_index(*stack_a) <= 2)
			rotates_swap(stack_a, 'a');
		else
			reverse_rotate_swap(stack_a, 'a');
	}
	push_x(stack_a, stack_b, 'b');
	while ((*stack_a)->index != find_min_index(*stack_a))
	{
		if (find_min_index(*stack_a) <= 2)
			rotates_swap(stack_a, 'a');
		else
			reverse_rotate_swap(stack_a, 'a');
	}
	push_x(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push_x(stack_b, stack_a, 'a');
	push_x(stack_b, stack_a, 'a');
}

void	sort_stack_few(t_node **stack_a, t_node **stack_b, int len_a)
{
	if (len_a == 5)
		sort_five(stack_a, stack_b);
	else
		sort_four(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int		len_a;

	len_a = ft_stack_len(*stack_a);
	if (len_a <= 5)
		sort_stack_few(stack_a, stack_b, len_a);
	else
	{
		while (len_a-- > 3 && !already_sorted(*stack_a))
			push_x(stack_a, stack_b, 'b');
		ft_printf("len: %i", len_a);
		if (len_a == 2)
			sort_three(stack_a);
		while (*stack_b)
		{
			init_values_stack(*stack_a, *stack_b);
			move_values(stack_a, stack_b);
		}
	}
	smallest_to_top(*stack_a);
}
