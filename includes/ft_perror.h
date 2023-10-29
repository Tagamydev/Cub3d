/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:09:10 by samusanc          #+#    #+#             */
/*   Updated: 2023/10/29 18:12:35 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERROR_H
# define FT_PERROR_H
# include <stdio.h>
# include <unistd.h>
# ifndef WRONG_ARGUMENTS
#  define WRONG_ARGUMENTS "Cub3d: Wrong arguments: Usage: ./cub3D map.cub\n"
# endif
# ifndef ERROR_TEST
#  define ERROR_TEST "Cub3d: Test: \n"
# endif

#endif
