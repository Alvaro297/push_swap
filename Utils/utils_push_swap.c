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

static long  ft_atol(const char *nptr)
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
