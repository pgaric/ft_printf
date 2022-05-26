/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:11:23 by pgaric            #+#    #+#             */
/*   Updated: 2022/05/26 10:55:28 by pgaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
int		ft_printunsigned(unsigned int n);
int		ft_printstring(char *str);
int		ft_printputchar(char c);
int		ft_printpointer(unsigned long n);
int		ft_printnumber(int n);
int		ft_printhexad(unsigned int n, char format);
int		ft_printf(const char *format, ...);

#endif