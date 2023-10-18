/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:33:56 by samusanc          #+#    #+#             */
/*   Updated: 2023/06/05 17:55:32 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H

int		ft_format_char(char c, int *general_count);
int		ft_format_string(char *s, int *general_count);
int		ft_format_hex(va_list *values, int *general_counter, char format);
void	ft_format_numbers(va_list *argumets, int *general_counter, char format);
#endif
