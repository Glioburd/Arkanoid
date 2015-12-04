/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:34:59 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:35:00 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	sevenseg(char c, float x)
{
	if (c == '0')
		aff_zero(x);
	if (c == '1')
		aff_un(x);
	if (c == '2')
		aff_deux(x);
	if (c == '3')
		aff_trois(x);
	if (c == '4')
		aff_quatre(x);
	if (c == '5')
		aff_cinq(x);
	if (c == '6')
		aff_six(x);
	if (c == '7')
		aff_sept(x);
	if (c == '8')
		aff_huit(x);
	if (c == '9')
		aff_neuf(x);
}

void		aff_score(t_env *env)
{
	char	*scr;
	float	x;
	int		i;

	i = 0;
	x = -0.965f;
	scr = ft_itoa(env->score);
	while (scr[i] != '\0')
	{
		sevenseg(scr[i], x);
		i++;
		x += 0.06f;
	}
	free(scr);
}
