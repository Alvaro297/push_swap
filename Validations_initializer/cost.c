#include "../push_swap.h"

void	set_cheapest(t_node *b)
{
	long			best_match_value;
	t_node		*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}


void move_nodes(t_node **a, t_node **b)
{
	t_node *cheapest_node;
	int		value_node;

	cheapest_node = return_cheapest(*b);
	value_node = cheapest_node -> number;
	if (cheapest_node->above_median && cheapest_node->target->above_median)
	{
		rotate_both(a, b, cheapest_node);
		update_node_properties(a, b);
	}
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
	{
		reverse_rotate_both(a, b);
		update_node_properties(a, b);
	}
	finish_rotation(b, cheapest_node -> number, 'b');
	finish_rotation(a, cheapest_node -> target -> number, 'a');
	push_x(a, b, 'a');
	set_current_position(*a, *b);
}

void	finish_rotation(t_node **stack, int cheapest_value, char stack_name)
{
	t_node	*top_node;

	while ((*stack) -> number != cheapest_value)
	{
		top_node = get_number_cheapest_node(*stack, cheapest_value);
		if (top_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack, 'a');
			else
				ra(stack, 'b');
		}
		else
		{
			if (stack_name == 'a')
				rra(stack, 'a');
			else
				rra(stack, 'b');
		}
	}
}

t_node	*get_number_cheapest_node(t_node *stack, int cheapest_value)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		if (current -> number == cheapest_value)
			return (current);
		current = current -> next; 
	}
	print_error(ERROR_4);
	return (NULL);
}
