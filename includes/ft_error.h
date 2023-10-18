/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:50:26 by samusanc          #+#    #+#             */
/*   Updated: 2023/07/10 14:53:37 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ERROR_H
# define FT_ERROR_H
# define ERROR_INVALID_MAP "INVALID_MAP\nMake sure the .fdf file has permissions"
# include <stdio.h>
# include <unistd.h>
# include <libft.h>

void		ft_error_log(char *str);

#endif
