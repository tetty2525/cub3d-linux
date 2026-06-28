/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	i;
// 	char	j;
// 	char	k;
// 	char	l;

// 	i = 65;
// 	j = tolower(i);
// 	k = 65;
// 	l = ft_tolower(k);
// 	printf("%c:%d\n", i, i);
// 	printf("%c:%d\n", j, j);
// 	printf("%c:%d\n", k, k);
// 	printf("%c:%d\n", l, l);
// }
