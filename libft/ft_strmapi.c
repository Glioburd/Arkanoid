/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:45:29 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/02 16:15:14 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	ret = ft_strnew(ft_strlen(s));
	if (ret)
	{
		while (s[i] != '\0')
		{
			ret[i] = f(i, s[i]);
			i++;
		}
	}
	return (ret);
}
