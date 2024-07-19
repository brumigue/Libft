/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:42:26 by brumigue          #+#    #+#             */
/*   Updated: 2024/07/16 04:11:31 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *str1 = "";
    char c1 = 'o';
    char c2 = '\0';

    char *result;
    result = ft_strrchr(str1, c2);
    if (result)
        printf("Last char of '%c' in: %ld\n", c2, str1, result - str1);
    else
        printf("Character '%c' not found\n", c2, str1);

    return 0;
}*/
