/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 03:58:53 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/23 07:10:28 by brumigue         ###   ########.fr       */
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
	int	is_negative;

	is_negative = 0;
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	if (n < 0)
	{
		is_negative = -1;
		n = -n;
	}
	while (len > 0)
	{
		str[len - 1] = '0' - (n % 10);
		n /= 10;
		len--;
	}
	if (is_negative)
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
