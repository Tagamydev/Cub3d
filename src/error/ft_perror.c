/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:14:47 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/29 17:15:09 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	*ft_perror(char *error)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, error, ft_strlen(error));
	return (NULL);
}
