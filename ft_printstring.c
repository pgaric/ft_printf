/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:20:39 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:58 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *str)
{
	int	print_lenght;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	print_lenght = 0;
	while (str[print_lenght] != '\0')
	{
		write(1, &str[print_lenght], 1);
		print_lenght++;
	}
	return (print_lenght);
}
