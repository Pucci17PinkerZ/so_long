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

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb < 10)
	{
		nb += 48;
		ft_putchar_fd(nb, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = (nb % 10) + 48;
		ft_putchar_fd(nb, fd);
	}
	return ;
}

// int main (void)
// {
// 	ft_putnbr_fd(-0, 1);
// 	ft_putchar_fd('\n', 1);
// 		ft_putnbr_fd(-9, 1);
// 		ft_putchar_fd('\n', 1);
// 			ft_putnbr_fd(-10, 1);
// 			ft_putchar_fd('\n', 1);
// 				ft_putnbr_fd(-2147483648, 1);
// 				ft_putchar_fd('\n', 1);
// 					ft_putnbr_fd(2147483647, 1);
// 					ft_putchar_fd('\n', 1);
// 						ft_putnbr_fd(-9, 1);
// 						ft_putchar_fd('\n', 1);
// }