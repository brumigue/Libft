/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 03:58:53 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 04:23:38 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fillstr(char *str, int n, size_t len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		while (len > 1)
		{
			str[len - 1] = '0' - (n % 10);
			n /= 10;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			str[len - 1] = '0' + (n % 10);
			n /= 10;
			len--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fillstr(str, n, len);
	return (str);
}
