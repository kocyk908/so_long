/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:30:16 by lkoc              #+#    #+#             */
/*   Updated: 2024/03/21 12:30:17 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	what_format(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == '%')
		i += ft_putchar('%');
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		i += ft_putptr(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	va_start(args, format);
	i = 0;
	print_length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			print_length = print_length + what_format(args, format[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			print_length++;
			i++;
		}
	}
	va_end(args);
	return (print_length);
}
