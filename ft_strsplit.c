/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:50:24 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/16 11:57:01 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib.h"

static int	strclen(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && s[i] != c)
		++i;
	return (i);
}

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*s && s[0] != c)
		++count;
	if (*s)
		++i;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			++count;
		++i;	
	}
	return (count);
}

static char **make_world(char *s, char c, char **new_str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	/* Allocation de la first string */
	if (*s && s[0] != c)
		new_str[j++] = ft_strndup(&s[i], strclen(&s[i], c));
	/* --------------------------- */
	if (*s)
		++i;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			new_str[j++] = ft_strndup(&s[i], strclen(&s[i], c));
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

char	**ft_strsplit(char const *s, char c)
{
	int 	count;
	char	**new_str; 
	if (!s || !c)
		return (NULL);
	count = count_word((char *)s, c);
	/* Attribution de size du tab de tab + 1 pour le last NULL */
	if (!(new_str = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	/* Malloc / crea de la string */
	make_world((char *)s, c, new_str);
	/* Last character NULL */
	new_str[count++] = 0; 
	return (new_str);
}

int main()
{
	char *s = "      split       this for   me  !       ";
	char **arr;
	int i;

	i = 0;
	arr = ft_strsplit(s, ' ');
	while (i < 6)
		printf("%s\n", arr[i++]);
}
