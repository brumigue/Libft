/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:28:50 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 02:09:14 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup_str;

	len = ft_strlen(s);
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	ft_strlcpy(dup_str, s, len + 1);
	return (dup_str);
}
