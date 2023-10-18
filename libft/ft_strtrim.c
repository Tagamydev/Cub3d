/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:25:09 by samusanc          #+#    #+#             */
/*   Updated: 2023/03/02 16:41:52 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_vc(char c, char *s);
static char	*ft_put_str(char *o, size_t l, char *s);
static char	*ft_trim(char *s1, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!set || !*set)
		return (ft_strdup(s1));
	if (!s1 || !*s1)
		return (ft_strdup(""));
	return (ft_trim((char *)s1, (char *)set));
}

static int	ft_vc(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

static char	*ft_put_str(char *o, size_t l, char *s)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		s[i] = o[i];
		++i;
	}
	return (s);
}

static char	*ft_trim(char *s1, char *set)
{
	size_t	i;
	size_t	f;
	size_t	l;
	int		s;
	char	*r;

	i = 0;
	f = 0;
	l = 0;
	while (s1[i] && ft_vc(s1[i], set) == 1)
		++i;
	while (s1[l])
		++l;
	f = l - 1;
	while (s1[f] && ft_vc(s1[f], set) == 1)
		--f;
	f = (l - 1) - f;
	s = l - (i + f);
	if (s < 0)
		return (ft_strdup(""));
	r = malloc (sizeof(char) * (s + 1));
	if (!r)
		return (NULL);
	r[s] = '\0';
	return (ft_put_str((s1 + i), s, r));
}
/*
int	main()
{
	printf("%s", ft_strtrim("              ", " "));
}*/
