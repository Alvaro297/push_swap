#include "../push_swap.h"

void	push_x(t_node **stack_dest, t_node **stack_src, char c)
{
	t_node	*tmp;

	if (*stack_src)
	{
		tmp = *stack_src;
		*stack_src = (*stack_src)->next;
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
	ft_printf("p%c\n", c);
}
