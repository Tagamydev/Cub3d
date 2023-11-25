/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:50 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/24 20:32:40 by lyandriy         ###   ########.fr       */
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

size_t	ft_strlcpys(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
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
			if(!get_color(line, count, &rgb[numb], &numb))
				return (0);
			if (line[*count] == '\n' && numb != 3)
				return (0);
		}
		*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
	return (1);
}

int	data_addres(void *mlx, char *line, t_img **img, int *count)
{
	int		tocount;
	char	*path;

	tocount = 0;
	*count += 2;
	while (line[*count] == ' ')
		*count += 1;
	if (line[*count])
	{
		while (line[*count + tocount] != '\0' && line[*count + tocount] != '\t'
			&& line[*count + tocount] != ' ')
			tocount++;
		path = malloc(sizeof(char) * (tocount + 1));
		if (!path)
			return (0);
		ft_strlcpys(path, &line[*count], tocount);
		while (line[*count + tocount] != '\0' && (line[*count + tocount] == '\t'
			|| line[*count + tocount] == ' '))
			tocount++;
		if (line[*count + tocount] && line[*count + tocount] != '\n')
		{
			free(path);
			return (0);
		}
		*img = ft_open_img(mlx, path);
		free(path);
	}
	return (1);
}

int	fill_struct(t_cub *cub, char *line)
{
	int		count;

	count = 0;
	while (line[count] == ' ')
		count++;
	if (!ft_strncmp(&line[count], "NO ", 3) && !cub->no_texture)
		return (data_addres(cub->mlx, line, &cub->no_texture, &count));
	else if (!ft_strncmp(&line[count], "SO ", 3) && !cub->so_texture)
		return (data_addres(&cub->mlx, line, &cub->so_texture, &count));
	else if (!ft_strncmp(&line[count], "EA ", 3) && !cub->ea_texture)
		return (data_addres(&cub->mlx, line, &cub->ea_texture, &count));
	else if (!ft_strncmp(&line[count], "WE ", 3) && !cub->we_texture)
		return (data_addres(&cub->mlx, line, &cub->we_texture, &count));
	else if (!ft_strncmp(&line[count], "F ", 2) && cub->color_ground == -1)
		return (identifier_color(line, &cub->color_ground, &count));
	else if (!ft_strncmp(&line[count], "C ", 2) && cub->color_sky == -1)
		return (identifier_color(line, &cub->color_sky, &count));
	else if (line[count] == '1' && cub->no_texture && cub->so_texture
		&& cub->ea_texture && cub->we_texture && cub->color_ground != -1
		&& cub->color_sky != -1)
		return (2);
	else if (line[count] != '\n' && line[count] != '\0')
		return (0);
	return (1);
}
