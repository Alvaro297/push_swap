#include "../push_swap.h"

size_t ft_strlen_push_swap(char **argv)
{
	size_t i = 0;

	while (argv[i] != NULL)
	{
		i++;
	}
	return (i);
}

long  ft_atol(const char *nptr)
{
	int		i;
	int 	sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

t_node	*find_smallest(t_node *stack)
{
	long	i;
	t_node	*current;
	t_node	*min_stack;

	current = stack;
	while (current != NULL)
	{
		if (current < i)
		{
			i = current -> number;
			min_stack = current;
		}
		current = current -> next;
	}
	return (min_stack);
}

int find_min_index(t_node *stack)
{
	int min_index; 
	int min_value;
	t_node *current; 
	
	min_value = stack->number;
	current = stack->next;
	min_index = stack->index;
	while (current != NULL)
	{
		if (current->number < min_value)
		{
			min_value = current->number;
			min_index = current->index;
		}
		current = current->next;
	}
	return (min_index);
}
