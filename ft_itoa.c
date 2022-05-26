/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:31:10 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:25 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nlen(int n)
{
	int	nlen;

	nlen = 0;
	if (-2147483648 < n && n <= 0)
	{
		n = -1 * n;
		nlen = 1;
	}
	else if (n == -2147483648)
	{
		return (11);
	}
	while (n > 0)
	{
		n = n / 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_copy(char *string, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_reverse(char *string, int i)
{
	int		k;
	char	temp;

	k = 0;
	if (string[k] == '-')
		k = 1;
	while (k < i)
	{
		temp = string[k];
		string[k] = string[i - 1];
		string[i - 1] = temp;
		k++;
		i--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		size;

	size = ft_nlen(n);
	string = (char *)malloc(size + 1);
	if (string == NULL)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (-2147483648 < n && n < 0)
		{
			n = -1 * n;
			string[i++] = '-';
		}
		if (n == -2147483648)
			return (ft_copy(string, "-2147483648"));
		string[i] = ((n % 10) + 48);
		n = n / 10;
	}
	string[i] = '\0';
	return (ft_reverse(string, i));
}
