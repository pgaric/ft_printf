/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:47:31 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 18:44:04 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printputchar(char c)
{
	write(1, &c, 1);
	return (1);//printing char and returning int 1, each time
}

int	ft_printstring(char *str)
{
	int	print_lenght;

	if (str == NULL)//edge case to check
	{
		write(1, "(null)", 6);
		return (6);
	}
	print_lenght = 0;
	while (str[print_lenght] != '\0')
	{
		write(1, &str[print_lenght], 1);//printing string and counting lenght;
		print_lenght++;
	}
	return (print_lenght);
}
//ft_itoa
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
//finish itoa.

int	ft_printnumber(int n)
{
	int		print_lenght;
	char	*str;

	str = ft_itoa(n);//itoa is writting the int number into the string
	print_lenght = ft_printstring(str);//printing out the string and returning the lenght value
	free(str);//release the memmory
	return (print_lenght);
}
//Start pointer conversion
int ft_pointerlenght(unsigned long n)
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
int ft_printpointer(unsigned long n)
{
	if (n == 0)
	{
		write(1, "0x0", 3); //edge case for Mac Operating system 0x0, as it will be test on that one, this is the output..Lunix output is "(nill)" and return (5), test on your machine with main
		return (3);
	}
	else
	{
		write (1, "0x", 2);
		ft_printing_pointer(n);	
	}
	return (ft_pointerlenght(n) + 2);	
}
//end pointer conversion
//start u ,unsignedint
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
		print_lenght = ft_printstring(str);//printing out the string and returning the lenght value
		free(str);
		return (print_lenght);
	}
}
//end u , unsigned int
//start hex conversion
int ft_heaxalenght(unsigned int n)
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
//end conversion hex
int	ft_placeholders(va_list args, char format)//format is a character (c,s,d,i,u,p,x,X or %)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')//conversion placeholder type: c = va_arg(args, int)
		print_lenght += ft_printputchar(va_arg(args, int));//every time, we call va_arg() to move to the next variable in memory we pass the name of the variable args and the type of the variable to va_arg
	else if (format == 's')//conversion placeholder type: s = va_arg(args, char *)
		print_lenght += ft_printstring(va_arg(args, char *));
	else if (format == 'd' || format == 'i')//conversion placeholder type: d = va_arg(args, int)
		print_lenght += ft_printnumber(va_arg(args, int));//first itao is returning the string, then printstring with lenght.
	else if (format == 'u')//conversion placeholder type: u = va_arg(args, unsigned int)
		print_lenght += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'p')//conversion placeholder type: p =  va_arg(args, unsigned long)
		print_lenght += ft_printpointer(va_arg(args, unsigned long));
	else if (format == 'x' || format == 'X')
		print_lenght += ft_printhexad(va_arg(args, unsigned int), format);// passing also a char format (x or X)
	else if (format == '%')//prints the % sign if it is %% ..
		print_lenght += ft_printputchar('%');
	return (print_lenght);
}

int	ft_printf(const char *format, ...)// ... means that the arguments are not static, they varies
{
	va_list	args; //creating head pointer to the list
	int		i;
	int		print_lenght;//ft_printf returns the lenght of the hole string under "--- " (excluding % sign)

	va_start(args, format);//initialisation, passing the name of the variable args and the last known element, in our case format
	print_lenght = 0;
	i = 0;
	while (format[i] != '\0')//going through whole string e.g "asd %d %d%%"
	{
		if (format[i] != '%') //if it is without placeholders
			print_lenght += ft_printputchar(*(format + i)); //printing each character + adding the lenght value by +1
		else if (format[i] == '%')
		{
			print_lenght += ft_placeholders(args, *(format + i + 1));// i + 1 = means that we are skipping % sign, and going first next to it..
			i++;//to skip the placeholders sign
		}
		i++;
	}
	va_end(args);//when we are done, we close this function
	return (print_lenght);
}

int	main(void)
{
	int	print_lenght;
	int	*p;
	int	t = 2;
	p = &t;
	printf("start your ft_printf\n");
	print_lenght = ft_printf("|ft_print, %c %s %d %i %% %x %X, %p, %u|",'K', "yes", -512, 0, 98731, 98731, p, -1);
	printf("\nReturn value: %d\n", print_lenght);
	printf("end\n");
	printf("Print function:\n");
	printf("|ft_print, %c %s %d %i %% %x %X, %p, %u|",'K', "yes", -512, 0, 98731, 98731, p, -1);
	printf("\n");
	return (0);
}
