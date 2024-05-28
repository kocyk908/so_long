/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:21:55 by lkoc              #+#    #+#             */
/*   Updated: 2024/03/21 15:21:57 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_hex(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static void	fill_hex_str(char *str, unsigned int nbr, int len, int up_or_low)
{
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		if ((nbr % 16) <= 9)
			str[len] = (nbr % 16) + '0';
		else
		{
			if (up_or_low == 1)
				str[len] = (nbr % 16) - 10 + 'A';
			else
				str[len] = (nbr % 16) - 10 + 'a';
		}
		nbr /= 16;
	}
}

int	ft_puthex(unsigned int nbr, int up_or_low)
{
	int		len;
	char	*hex_str;

	len = ft_strlen_hex(nbr);
	hex_str = (char *)malloc(len + 1);
	if (!hex_str)
		return (0);
	fill_hex_str(hex_str, nbr, len, up_or_low);
	ft_putstr(hex_str);
	free(hex_str);
	return (len);
}
