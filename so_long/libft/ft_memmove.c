/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfiora-d <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/10/03 12:43:43 by nfiora-d         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*psrc;
	char		*pdest;

	psrc = src;
	pdest = dest;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else if (dest > src)
	{
		while (n--)
			pdest[n] = psrc[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char src1[] = "12345678";
// 	printf("%s\n",(char *)ft_memmove(src1 +3, src1 , 5));
// 	char src2[] = "12345678";
// 	printf("%s",(char *)memmove(src2 +3, src2 , 5));
// 	return (0);
// }