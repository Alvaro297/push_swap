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
		swap_change(stack, 'a'); // Case 1: 2 1 3 → 1 2 3
	else if (a > b && b > c)
	{
		swap_change(stack, 'a'); // Case 2: 3 2 1 → 2 3 1
		reverse_rotate(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stack, 'a'); // Case 3: 3 1 2 → 1 2 3
	else if (a < b && b > c && a < c)
	{
		swap_change(stack, 'a'); // Case 5: 1 3 2 → 3 1 2
		rotate(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a'); // Case 4: 2 3 1 → 1 2 3
}

void sort_four(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->index != find_min_index(*stack_a))
	{
		if (find_min_index(*stack_a) <= 2)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	push_x(stack_b, stack_a, 'b');
	sort_three(stack_a);
	push_x(stack_a, stack_b, 'a');
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->index != find_min_index(*stack_a))
	{
		if (find_min_index(*stack_a) <= 2)
			rotates_swap(stack_a, 'a');
		else
			reverse_rotate_swap(stack_a, 'a');
	}
	push_x(stack_b, stack_a, 'b');
	while ((*stack_a)->index != find_min_index(*stack_a))
	{
		if (find_min_index(*stack_a) <= 2)
			rotates_swap(stack_a, 'a');
		else
			reverse_rotate_swap(stack_a, 'a');
	}
	push_x(stack_b, stack_a, 'b'); 
	sort_three(stack_a);
	push_x(stack_a, stack_b, 'a');
	push_x(stack_a, stack_b, 'a');
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
		while (len_a -- > 3 && !already_sorted(*stack_a))
			push_x(stack_b, stack_a, 'b');
	}
	if (len_a == 3)
		sort_three(&stack_a);
	while (*stack_b != NULL)
	{
		init_values_stack(*stack_a, *stack_b);
		move_values(stack_a, stack_b);
	}
	free(stack_b);
	smallest_to_top(stack_a);
}
