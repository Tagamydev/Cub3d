/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:50 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/25 19:27:13 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	aux_data_addres(char *line, int *count, int *tocount, char *path)
{
	while (line[*count + *tocount] != '\0' && line[*count + *tocount] == ' ')
		*tocount += 1;
	if (line[*count + *tocount] && line[*count + *tocount] != '\n')
	{
		free(path);
		return (0);
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
		while (line[*count + tocount] != '\0' && line[*count + tocount] != ' ')
			tocount++;
		path = malloc(sizeof(char) * (tocount + 1));
		if (!path)
			return (0);
		ft_strlcpys(path, &line[*count], tocount);
		if (!aux_data_addres(line, count, &tocount, path))
			return (0);
		*img = ft_open_img(mlx, path);
		free(path);
	}
	return (1);
}

int	fill_struct(t_cub *cub, char *line)
{
	int	count;

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
	{
		printf("hola %c\n", line[count]);
		return (0);
	}
	return (1);
}
