/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*d;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	c = (char *)dst;
	d = (char *)src;
	while (i < n)
	{
		c[i] = d[i];
		i++;
	}
	return (c);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[10] = "aaaaaaaa";
// 	char	b[10] = "123456";

// 	ft_memcpy(a, b, 2);
// 	printf("%s\n", a);
// }
