#include "push_swap.h"

void	push_swap(char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	init_validations(argv);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		*argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	else
		print_error(ERROR_0);
	return (0);
}
