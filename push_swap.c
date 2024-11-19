#include "push_swap.h"

void	push_swap(char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size_stack;

	a = NULL;
	b = NULL; 
	init_validations(a, argv);
	already_sorted(a);
	size_stack = ft_stack_len(a);
	if (size_stack < 4)
	{
		if (size_stack == 3)
			sort_three(&a);
		else if (size_stack == 2)
			swap_change(&a, 'a');
		else
			sort_stack(&a, &b);
	}
	free(&a);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		*argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
	}
	else
		print_error(ERROR_0);
	return (0);
}
