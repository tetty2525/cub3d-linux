/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sumlen;
	size_t	i;
	char	*dest;
	char	*s_1;
	char	*s_2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sumlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = (char *)ft_calloc(sumlen + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		dest[i++] = *s_1++;
	while (*s_2)
		dest[i++] = *s_2++;
	dest[i] = '\0';
	return (dest);
}
