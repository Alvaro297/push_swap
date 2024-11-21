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

void	get_target_node(t_node *stack_a, t_node *stack_b)
{
	long	i;
	t_node	*current;

	i = LONG_MAX;
	current = stack_a;
	while (stack_b != NULL)
	{
		while (current != NULL)
		{
			if ((current -> number > stack_b -> number) 
				&& i > current -> number - stack_b -> number)
			{
				i = current -> number - stack_b -> number;
				stack_b -> target = current; 
			}
			current = current -> next;
		}
		if (i == LONG_MAX)
			stack_b -> target = get_minimum_value(stack_a);
		stack_b = stack_b -> next;
	}
}

t_node	*get_minimum_value(t_node	*stack_x)
{
	long	i;
	t_node	*current;
	t_node	*minvalue;

	i = LONG_MAX;
	current = stack_x;
	while (current != NULL)
	{
		if (current -> number < i)
			minvalue = current;
		current = current -> next;
	}
	return (minvalue);
}

void	set_pricecost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target->above_median)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - (b->target->index);
		b = b->next;
	}
}

void	init_values_stack(t_node *stack_a, t_node *stack_b)
{
	medianvalue(stack_a, stack_b);
	get_target_node(stack_a, stack_b);
	set_pricecost(stack_a, stack_b);
	get_cheapest_cost(stack_a, stack_b);
}
