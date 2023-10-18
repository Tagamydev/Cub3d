/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:41 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 14:26:10 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía el número ’n’ al file descriptor dado.*/
void	ft_putnbr_fd(int n, int fd)
{
	long	nd;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	nd = (long)n;
	if (n > 9)
		ft_putnbr_fd((int)(nd / 10), fd);
	ft_putchar_fd(nd % 10 + '0', fd);
}
/*
int	main()
{
	int	i;

	i = (-2147483647 -1);
	ft_putnbr_fd(i, 1);
}*/
