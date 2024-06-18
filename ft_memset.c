/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 05:19:46 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/18 05:48:45 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr = (unsigned char *) s;
	unsigned char	uc = (unsigned char) c;
	size_t			i;

	i = 0;
	while (i < n)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}
