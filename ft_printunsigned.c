/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:22:29 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:57:39 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedlenght(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	int		lenght;

	lenght = ft_unsignedlenght(n);
	str = (char *)malloc(sizeof(char) * (lenght + 1));
	if (str == NULL)
		return (0);
	str[lenght] = '\0';
	while (n != 0)
	{
		str[lenght - 1] = n % 10 + '0';
		n = n / 10;
		lenght--;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	char	*str;
	int		print_lenght;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
	{
		str = ft_itoa_unsigned(n);
		print_lenght = ft_printstring(str);
		free(str);
		return (print_lenght);
	}
}
