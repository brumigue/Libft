/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 03:58:53 by brumigue          #+#    #+#             */
/*   Updated: 2024/07/04 02:17:06 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;
	int		is_neg;

	len = 1;
	is_neg = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len + is_neg);
}

static void	fillstr(char *str, int n, size_t len)
{
	int	is_neg;

	is_neg = 0;
	str[len] = '\0';
	if (n == -2147483648)
	{
		ft_memcpy(str, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	while (len > 0)
	{
		str[len - 1] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	if (is_neg)
		str[0] = '-';
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
