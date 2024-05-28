/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:34:37 by prossi            #+#    #+#             */
/*   Updated: 2021/09/15 14:38:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

//#include <string.h>

// int main(void)
// {
//     char str1[] = "Hello, world!";
//     char str2[] = "Hello, world!";

//     ft_bzero(str1, 5);
//     bzero(str2, 5);

//     if (memcmp(str1, str2, sizeof(str1)) == 0)
//     {
//         printf("Test passed: ft_bzero and bzero same result.\n");
//     }
//     else
//     {
//         printf("Test failed: ft_bzero and bzero different results.\n");
//     }

//     return 0;
// }
