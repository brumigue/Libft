/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumigue <brumigue@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:57:06 by brumigue          #+#    #+#             */
/*   Updated: 2024/06/30 03:53:28 by brumigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int main(void)
{
	const char *str1 = "12345";
    const char *str2 = "   -12345";
    const char *str3 = "   +12345";
    const char *str4 = "   12345abc";
    const char *str5 = "abc12345";
    const char *str6 = "   -+12345";
    const char *str7 = "\t\n\r\v\f 12345";
    const char *str8 = "0";

    printf("'%s' -> %d\n", str1, ft_atoi(str1));
    printf("'%s' -> %d\n", str2, ft_atoi(str2));
    printf("'%s' -> %d\n", str3, ft_atoi(str3));
    printf("'%s' -> %d\n", str4, ft_atoi(str4));
    printf("'%s' -> %d\n", str5, ft_atoi(str5));
    printf("'%s' -> %d\n", str6, ft_atoi(str6));
    printf("'%s' -> %d\n", str7, ft_atoi(str7));
    printf("'%s' -> %d\n", str8, ft_atoi(str8));

    return (0);
}
