/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:54:07 by samusanc          #+#    #+#             */
/*   Updated: 2023/02/06 14:54:12 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía la string ’s’ al file descriptor dado,
seguido de un salto de línea.*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!(!s))
	{
		ft_putstr_fd(s, fd);
		write (fd, "\n", 1);
	}
}
