/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:52:57 by prossi            #+#    #+#             */
/*   Updated: 2021/09/15 17:06:22 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = ft_strlen2(src);
	i = 0;
	d = 0;
	if (size == 0)
	{
		return (s);
	}
	while (dst[i] && i < size)
		i++;
	d = i;
	while (src[i - d] && i < size - 1)
	{
		dst[i] = src[i - d];
		i++;
	}
	if (d < size)
		dst[i] = '\0';
	return (d + s);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[] = "slowo";

// 	printf("%ld", ft_strlcat(dest, "0123456789", 5));
// 	return (0);
// }
