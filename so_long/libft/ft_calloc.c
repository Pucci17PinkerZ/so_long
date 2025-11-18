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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	return (ft_bzero(ptr, nmemb * size), ptr);
}

// #include <stdio.h>
// int main (void)
// {
// 	char *addr = ft_calloc(0,0);
// 	// for(int i = 0;i < 5; i++)
// 	// 	addr[i] = ('a' + i);
// 	// for(int j = 0;j < 6; j++)
// 		printf("%p ", addr);
// 		if(free(addr))
// 			printf("%s", "ok!!!");
// 		printf("%p", NULL);
// }