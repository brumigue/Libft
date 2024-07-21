/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:28:02 by brumigue          #+#    #+#             */
/*   Updated: 2024/07/21 02:10:41 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest_ptr > src_ptr && dest_ptr < src_ptr + n)
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*(--dest_ptr) = *(--src_ptr);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
