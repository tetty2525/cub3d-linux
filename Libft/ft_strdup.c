/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	char	*p;
	size_t	len;

	buff = (char *)s;
	len = ft_strlen(buff);
	if (s == NULL)
		return (NULL);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s, len + 1);
	p[len] = '\0';
	return (p);
}
