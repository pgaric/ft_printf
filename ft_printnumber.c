/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:29:51 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:48 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumber(int n)
{
	int		print_lenght;
	char	*str;

	str = ft_itoa(n);
	print_lenght = ft_printstring(str);
	free(str);
	return (print_lenght);
}
