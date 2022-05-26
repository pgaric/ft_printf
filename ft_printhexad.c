/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:26:17 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:41 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_heaxalenght(unsigned int n)
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

int	ft_printhexad(unsigned int n, char format)
{	
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else if (n >= 16)
	{
		ft_printhexad(n / 16, format);
		ft_printhexad(n % 16, format);
	}
	else if (n <= 9)
		ft_putchar_fd((n + '0'), 1);
	else
	{
		if (format == 'X')
			ft_putchar_fd((n - 10 + 'A'), 1);
		if (format == 'x')
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
	return (ft_heaxalenght(n));
}
