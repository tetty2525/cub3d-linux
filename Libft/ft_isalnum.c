/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('a'));
// 	printf("%d\n", isalnum('a'));
// 	printf("%d\n", ft_isalnum('0'));
// 	printf("%d\n", isalnum('0'));
// 	printf("%d\n", ft_isalnum('-'));
// 	printf("%d\n", isalnum('-'));
// 	printf("%d\n", ft_isalnum(' '));
// 	printf("%d\n", isalnum(' '));
// 	return (0);
// }
