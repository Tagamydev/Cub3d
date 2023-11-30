/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:38:51 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	go_over_space(char *line, int *count)
{
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count] == ',')
		*count += 1;
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count] != '\n' && line[*count] != '\0'
		&& !ft_isdigit(line[*count]))
		return (0);
	return (1);
}

int	get_color(char *line, int *count, int *rgb, int *numb)
{
	int		to_count;
	char	*digit;

	to_count = 0;
	if (!ft_isdigit(line[*count]) || *numb >= 3)
		return (0);
	while (ft_isdigit(line[*count + to_count]))
		to_count++;
	digit = malloc(sizeof(char) * (to_count + 1));
	if (!digit)
		return (0);
	if (!ft_strlcpys(digit, &line[*count], (to_count + 1)))
	{
		free(digit);
		return (0);
	}
	*count += to_count;
	*rgb = ft_atoi(digit);
	free(digit);
	if (*rgb < 0 || *rgb > 255)
		return (0);
	*numb += 1;
	if (!go_over_space(line, count))
		return (0);
	return (1);
}

int	identifier_color(char *line, int *color, int *count)
{
	int	numb;
	int	rgb[3];

	numb = 0;
	*count += 2;
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count])
	{
		while (line[*count] && line[*count] != '\n')
		{
			if (!get_color(line, count, &rgb[numb], &numb))
				return (0);
			if (line[*count] == '\n' && numb != 3)
				return (0);
		}
		*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
	return (1);
}
