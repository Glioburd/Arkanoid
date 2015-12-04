/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:34:03 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:34:04 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ft_error(const char *str)
{
	ft_putstr("ft_ls: ");
	if (!str)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
	}
	else
		perror(str);
}
