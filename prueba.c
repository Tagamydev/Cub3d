/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:21:44 by lyandriy          #+#    #+#             */
/*   Updated: 2023/11/23 18:23:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void f(void)
{
	system("leaks -q a.out");
}

int main()
{
	atexit(f);
	int i = 2;
	int *iptr = &i;
	char c = 'a';
	char *cptr = &c;
	char **matrix;

	int j = 0;
	int *i_array = malloc(sizeof(int) * 4);
	i_array[0] = 1;
	i_array[1] = 1;
	i_array[2] = 1;
	i_array[3] = 1;

	char	stack_arr[100] = "Mi cadena, UWU";

	matrix = malloc(sizeof(char *) * 2);
	matrix[0] = malloc(sizeof(char) * 2);
	matrix[0][0] = 'h';
	matrix[0][1] = '\0';
	matrix[1] = NULL;
	printf("%s\n", matrix[0]);
	free(matrix[0]);
	free(matrix[1]);
	free(matrix);
	//free(iptr);
}


CUB
cub->no_texture
cub->so_texture
cub->ea_texture
cub->we_texture