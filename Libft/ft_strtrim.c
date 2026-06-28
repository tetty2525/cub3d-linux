/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		last = ft_strlen((char *)s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > start)
			last--;
		str = (char *)malloc(sizeof(char) * (last - start + 1));
		if (str == NULL)
			return (NULL);
		else
		{
			if (str)
				ft_strlcpy(str, &s1[start], last - start + 1);
		}
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     char test[20]="1234AAA22331122";
//     char trim[10]="1234";
//     char *result=ft_strtrim(test,trim);

//     printf("%s\n",result);
//     free(result);

// }
