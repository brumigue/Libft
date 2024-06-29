/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:34:57 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 06:58:07 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*next_word(char const **s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	word = ft_substr(*s, 0, len);
	while (**s == c)
		(*s)++;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;
	size_t	i;

	word_count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	if (!s)
		return (NULL);
	if (!split)
		return (NULL);
	while (i < word_count)
	{
		split[i] = next_word(&s, c);
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		i++;
	}
	split[word_count] = NULL;
	return (split);
}
