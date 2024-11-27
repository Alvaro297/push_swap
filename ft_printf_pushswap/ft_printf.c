/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 10:01:35 by alvamart          #+#    #+#             */
/*   Updated: 2024-10-18 10:01:35 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_params(char param, va_list arg)
{
	if (param == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (param == '%')
		return (ft_print_char('%'));
	else if (param == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (param == 'p')
		return (ft_print_pbase(va_arg(arg,
					unsigned long int), "0123456789abcdef"));
	else if (param == 'd' || param == 'i')
		return (ft_printf_nbr(va_arg(arg, int)));
	else if (param == 'u')
		return (ft_print_ubase((unsigned long int)
				va_arg(arg, unsigned int), "0123456789"));
	else if (param == 'x')
		return (ft_print_ubase(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (param == 'X')
		return (ft_print_ubase(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		len;
	va_list	arg;
	int		ret;

	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else
		{
			ret = check_params(format[++i], arg);
			len += ret;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
/*
int main(void)
{
int ret_ft;
	int ret_std;

	// Pruebas con combinaciones mixtas
	ret_ft = ft_printf("Combinando: entero: %d, cadena: %s, char: %c, hex: %x, 
	unsigned: %u, porcentaje: %%\n", 42, "Hello", 'A', 255, 3000000000U);
	ret_std = printf("Combinando: entero: %d, cadena: %s, char: %c, hex: %x, 
	unsigned: %u, porcentaje: %%\n", 42, "Hello", 'A', 255, 3000000000U);
	printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Mix: char: %c, puntero: %p, unsigned: %u, negativo: %d,
			cadena vacía: %s\n", 'Z', (void*)main, 123456789U, -123, "");
	ret_std = printf("Mix: char: %c, puntero: %p, unsigned: %u, negativo: %d,
			cadena vacía: %s\n", 'Z', (void*)main, 123456789U, -123, "");
	printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Hexadecimal en mayúsculas y 
	minúsculas: %x %X\n", 48879, 48879);
	ret_std = printf("Hexadecimal en mayúsculas y 
	minúsculas: %x %X\n", 48879, 48879);
	printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Mixto con límites: int min: %d, int max:%d, unsigned max:
			%u\n", -2147483647, 2147483647, 4294967295U);
	ret_std = printf("Mixto con límites: int min: %d, int max: %d,unsigned max:
			%u\n", -2147483647, 2147483647, 4294967295U);
	printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Probando porcentaje: %%\n");
	ret_std = printf("Probando porcentaje: %%\n");
	printf("ft_printf devolvió: %d, printf devolvió: %d\n\n", ret_ft, ret_std);
	// Pruebas básicas con ft_printf
	ft_printf("Probando enteros: %d\n", 42);
	ft_printf("Probando negativos: %d\n", -42);
	ft_printf("Probando cadenas: %s\n", "Hola, mundo!");
	ft_printf("Probando caracteres: %c\n", 'A');
	ft_printf("Probando hexadecimales: %x\n", 0);
	ft_printf("Probando punteros: %p\n", (void*)main);
	ft_printf("Probando unsigned: %u\n", 3000000000U);
	ft_printf("Probando porcentaje: %%\n");

	// También puedes comparar con printf para verificar la salida
	printf("Comparando con printf:\n");
	printf("Probando enteros: %d\n", 42);
	printf("Probando negativos: %d\n", -42);
	printf("Probando cadenas: %s\n", "Hola, mundo!");
	printf("Probando caracteres: %c\n", 'A');
	printf("Probando hexadecimales: %x\n", 0);
	printf("Probando punteros: %p\n", (void*)main);
	printf("Probando unsigned: %u\n", 3000000000U);
	printf("Probando porcentaje: %%\n");

	return 0;
}*/