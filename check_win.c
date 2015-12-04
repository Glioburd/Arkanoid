/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:33:34 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:33:36 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		check_win(t_env *env)
{
	int		i;

	i = 0;
	while (env->map[i])
	{
		if (env->map[i] == '1' || env->map[i] == '2' || env->map[i] == '3')
			return (0);
		i++;
	}
	ft_putendl("GG, a winner is YOU! :D");
	return (1);
}
