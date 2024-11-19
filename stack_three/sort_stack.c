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

void	sort_five(t_node **stack_a, t_node **stack_b, int len_stack_a)
{
	while (len_stack_a -- > 3)
	{
		
	}
	
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int		len_a;

	len_a = ft_stack_len(*stack_a);
	if (len_a == 5)
		sort_five(&stack_a, &stack_b, len_a);
	else
	{
		while (len_a -- > 3)
			push_x(&stack_b, &stack_a, 'b');
	}
	sort_three(&stack_a);
	while (*stack_b)
	{
		init_values_stack(*stack_a, *stack_b);
	}
	
}
