#include "../push_swap.h"

void	rotates_swap(t_node **stack, char c)
{
	int		tmp;
	t_node	*current;

	if (!(*stack) || !((*stack)->next))
		return ;
	
	tmp = (*stack)->number;
	current = *stack;

	while (current->next != NULL)
	{
		current->number = current->next->number;
		current = current->next;
	}
	current->number = tmp;

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
	int		tmp;
	t_node	*current;

	if (!(*stack) || !((*stack)->next))
		return ;

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	tmp = current->number;
	while (current->prev != NULL)
	{
		current->number = current->prev->number;
		current = current->prev;
	}
	current->number = tmp;

	if (c != 'r')
		ft_printf("rr%c\n", c);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_swap(stack_a, 'r');
	reverse_rotate_swap(stack_b, 'r');
	ft_printf("rr");
}
