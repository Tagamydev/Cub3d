/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:23 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:38:13 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía el carácter ’c’ al file descriptor
especificado.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
