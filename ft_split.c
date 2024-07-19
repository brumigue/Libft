/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:34:57 by brumigue          #+#    #+#             */
/*   Updated: 2024/07/12 11:02:29 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_delimiter(char const *str, char c, int i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	next_word(char const *str, char c, int i)
{
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

static int	count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			i = next_delimiter(str, c, i);
		}
		else
			i++;
	}
	return (word);
}

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	words = count_words(str, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!str || !res)
		return (NULL);
	while (j < words)
	{
		i = next_word(str, c, i);
		res[j] = ft_substr(str, i, next_delimiter(str, c, i) - i);
		if (!res[j])
		{
			free_split(res);
			return (NULL);
		}
		i = next_delimiter(str, c, i);
		j++;
	}
	res[j] = NULL;
	return (res);
}
