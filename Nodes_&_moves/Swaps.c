#include "../push_swap.h"

void	swap_change(t_node **stack, char c)
{
	if (!(*stack) || !((*stack)->next))
		return;

	int tmp = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = tmp;

	if (c != 's')
		ft_printf("s%c\n", c);
}

void	both_swap(t_node **stack_a, t_node **stack_b)
{
	swap_change(stack_a, 's');
	swap_change(stack_b, 's');
	ft_printf("ss\n");
}
