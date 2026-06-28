/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buff;

	buff = (char *)s;
	while (*buff)
	{
		if (*buff == (char)c)
			return (buff);
		buff++;
	}
	if ((char)c == '\0')
		return (buff);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	test1[20] = "ilove42tokyo";
// 	char	test2[20] = "ilove42tokyo";

// 	printf("%s\n", strchr(test1, '4'));
// 	printf("%s\n", strchr(test1, '\0'));
// 	printf("%s\n", strchr(test1, 101));
// 	printf("%s\n", strchr(test1, 'h'));
// 	printf("%s\n", ft_strchr(test2, '4'));
// 	printf("%s\n", ft_strchr(test2, '\0'));
// 	printf("%s\n", ft_strchr(test2, 101));
// 	printf("%s\n", ft_strchr(test2, 'h'));
// }
