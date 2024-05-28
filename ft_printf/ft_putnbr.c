/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:23:38 by lkoc              #+#    #+#             */
/*   Updated: 2024/03/21 15:23:39 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = 11;
		write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	len += ft_putchar(n % 10 + '0');
	return (len);
}
/*
 * Ta funkcja wypisuje liczbę całkowitą 'n' na standardowe wyjście (stdout)
 * i zwraca długość tej liczby w znakach.
 *
 * 1. Najpierw sprawdza, czy 'n' jest równa najmniejszej
  	wartości dla typu int,
 *    W tym przypadku funkcja zwraca długość wypisanej liczby, czyli 11.
 *
 * 3. Jeśli 'n' jest większe niż 9 , funkcja wywołuje
 *    się rekurencyjnie z wartością 'n' / 10. Pozwala to na wypisanie
 *    wszystkich cyfr oprócz ostatniej. Długość jest dodawana do 'len'.
 *
 * 4. Na koniec wypisuje ostatnią cyfrę liczby, korzystając z ft_putchar.
 *    Jej wartość uzyskuje poprzez resztę z dzielenia 'n' przez 10, do której
 *    dodaje '0'. Długość wypisanej cyfry (zawsze 1) jest dodawana do 'len'.
 *
 * 5. Funkcja zwraca 'len', czyli całkowitą długość wypisanej liczby w znakach.
 */
