/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:36:52 by prossi            #+#    #+#             */
/*   Updated: 2021/09/15 14:44:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}
/*
#include <string.h>

int main (void)
{
   char strOG[50];
   char strMI[50];

   strcpy(strOG,"This is string.h library function");
   puts(strOG);

   memset(strOG,'$',7);
   puts(strOG);

	printf("\n");

   strcpy(strMI,"This is function I made");
   puts(strMI);

   ft_memset(strMI,'$',7);
   puts(strMI);

   return(0);
}*/
