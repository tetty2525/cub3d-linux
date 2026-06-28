/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				minus_flag;
	int				i;

	n = 0;
	minus_flag = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		str++;
	i++;
	if (*str == '-')
	{
		minus_flag = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (minus_flag)
		n *= -1;
	return ((int)n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("ft_atoi\n");
// 	printf("%d\n", ft_atoi("   123"));
// 	printf("%d\n", ft_atoi("-123"));
// 	printf("%d\n", ft_atoi("1234567890"));
// 	printf("%d\n", ft_atoi("12345678901"));
// 	printf("%d\n", ft_atoi("12.34"));
// 	printf("%d\n", ft_atoi("abc"));
// 	printf("\n");
// 	printf("atoi\n");
// 	printf("%d\n", atoi("   123"));
// 	printf("%d\n", atoi("-123"));
// 	printf("%d\n", atoi("1234567890"));
// 	printf("%d\n", atoi("12345678901"));
// 	printf("%d\n", atoi("12.34"));
// 	printf("%d\n", atoi("abc"));
// }
