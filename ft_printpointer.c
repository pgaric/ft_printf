/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:24:31 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 12:03:40 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointerlenght(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_printing_pointer(unsigned long n)
{	
	if (n >= 16)
	{
		ft_printing_pointer(n / 16);
		ft_printing_pointer(n % 16);
	}
	else if (n <= 9)
		ft_putchar_fd((n + '0'), 1);
	else
		ft_putchar_fd((n - 10 + 'a'), 1);
}

int	ft_printpointer(unsigned long n)
{
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write (1, "0x", 2);
		ft_printing_pointer(n);
	}
	return (ft_pointerlenght(n) + 2);
}
