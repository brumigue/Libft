/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:41:10 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 06:26:14 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
