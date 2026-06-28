/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
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

// 	i = 97;
// 	j = toupper(i);
// 	k = 97;
// 	l = ft_toupper(k);
// 	printf("%c:%d\n", i, i);
// 	printf("%c:%d\n", j, j);
// 	printf("%c:%d\n", k, k);
// 	printf("%c:%d\n", l, l);
// }
