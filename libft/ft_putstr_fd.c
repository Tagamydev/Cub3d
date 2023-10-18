/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:54 by samusanc          #+#    #+#             */
/*   Updated: 2023/02/06 14:53:56 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía la string ’s’ al file descriptor
especificado.*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!(!s))
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			++i;
		}
	}
}
