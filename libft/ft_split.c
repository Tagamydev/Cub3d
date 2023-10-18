/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:28:39 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/09 13:37:53 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_p_word(char *s, char c)
{
	char	*str;
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	while (s[l] && s[l] != c)
		++l;
	str = malloc (sizeof(char) * (l + 1));
	if (!str)
		return (0);
	str[l] = '\0';
	while (i < l)
	{
		str[i] = *s;
		++s;
		++i;
	}
	return (str);
}

static void	ft_get_str(char *s, char c, char **r)
{
	size_t	i;

	i = 0;
	while (*s && *s == c)
		++s;
	while (*s)
	{
		r[i] = ft_p_word((char *)s, c);
		if (!r[i] && r[0])
		{
			while (i != 0)
			{
				free(r[i]);
				r[i] = NULL;
				--i;
			}
			free(r);
			return ;
		}
		++i;
		while (*s && *s != c)
			++s;
		while (*s && *s == c)
			++s;
	}
}

static size_t	ft_n_words(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s == c)
		++s;
	while (*s)
	{
		++i;
		while (*s && *s != c)
			++s;
		while (*s && *s == c)
			++s;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**r;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_n_words((char *)s, c);
	r = malloc (sizeof(char *) * (l + 1));
	if (!r)
		return (0);
	r[l] = 0;
	ft_get_str((char *)s, c, r);
	return (r);
}
