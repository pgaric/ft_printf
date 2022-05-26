/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:47:31 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:38 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_placeholders(va_list args, char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_printputchar(va_arg(args, int));
	else if (format == 's')
		print_lenght += ft_printstring(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_lenght += ft_printnumber(va_arg(args, int));
	else if (format == 'u')
		print_lenght += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		print_lenght += ft_printpointer(va_arg(args, unsigned long));
	else if (format == 'x' || format == 'X')
		print_lenght += ft_printhexad(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_lenght += ft_printputchar('%');
	return (print_lenght);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_lenght;

	va_start(args, format);
	print_lenght = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			print_lenght += ft_printputchar(*(format + i));
		else if (format[i] == '%')
		{
			print_lenght += ft_placeholders(args, *(format + i + 1));
			i++;
		}
		i++;
	}
	va_end(args);
	return (print_lenght);
}
