/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isalpha('a'));
// 	printf("%d\n", isalpha('a'));
// 	printf("%d\n", ft_isalpha('0'));
// 	printf("%d\n", isalpha('0'));
// 	printf("%d\n", ft_isalpha('-'));
// 	printf("%d\n", isalpha('-'));
// 	return (0);
// }
