/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:48:02 by brumigue          #+#    #+#             */
/*   Updated: 2024/07/21 02:43:53 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s1 || !s2 || !new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcat(new_str, s2, len1 + len2 + 1);
	return (new_str);
}
