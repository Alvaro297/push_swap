#include "../push_swap.h"

void print_error(char *message)
{
	ft_printf("\033[1;31mError: %s\033[0m\n", message);
	exit (1);
}

void print_info(char *message)
{
	ft_printf("\033[1;33mInfo: %s\033[0m\n", message);
	exit (1);
}