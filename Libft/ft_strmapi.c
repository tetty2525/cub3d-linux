/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	index;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	index = 0;
	if (f == NULL)
		ft_strlcpy(p, s, len);
	else
	{
		while (index < len)
		{
			p[index] = (*f)(index, s[index]);
			index++;
		}
		p[len] = '\0';
	}
	return (p);
}
