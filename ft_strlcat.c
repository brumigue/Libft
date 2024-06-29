/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:51:14 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 04:53:27 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len < size)
	{
		while (src[src_len] && dest_len < size - 1)
		{
			dest[dest_len + src_len] = src[src_len];
			src_len++;
		}
		dest[dest_len + src_len] = '\0';
	}
	return (dest_len + ft_strlen(src));
}
