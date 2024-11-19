# include "../push_swap.h"

void	medianvalue(t_node *stack_a, t_node *stack_b)
{
	int	len;
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

static void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	
}

void	init_values_stack(t_node *stack_a, t_node *stack_b)
{
	medianvalue(stack_a, stack_b);
	get_target_node(stack_a, stack_b);
}
