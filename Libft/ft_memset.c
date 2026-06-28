/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*string;

	i = 0;
	string = s;
	while (i < size)
	{
		string[i] = c;
		i++;
	}
	return (string);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int	s1[] = "abcdefg";
// 	int	s2[] = "abcdefg";

// 	printf("%s\n", memset(s1, 'x', 5));
// 	printf("%s\n", ft_memset(s1, 'x', 5));
// }
