/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:25:35 by lkoc              #+#    #+#             */
/*   Updated: 2024/03/21 15:25:38 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_print_hex(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
		len++;
	}
	else
	{
		write(1, &base[nbr], 1);
		len = 1;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	len += ft_print_hex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
